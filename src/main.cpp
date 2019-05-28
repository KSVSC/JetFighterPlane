#include "main.h"
#include "timer.h"
#include "display.h"
#include "ball.h"
#include "ground.h"
#include "aero.h"
#include "arrow.h"
#include "cannon.h"
#include "dashboard.h"
#include "volcano.h"
#include "smoke_ring.h"
#include "shoot.h"
#include "drop.h"
#include "parachutes.h"
#include "bullet.h"
#include "fly_bullet.h"
#include "fuel_tank.h"

using namespace std;

GLMatrices Matrices;
GLMatrices Trial;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/
int cannon_count = 20;
int bullet_count = cannon_count;
int volcano_count = 10;
int ring_count = 5;
int parachutes_count = 3;
int flybullet_count = parachutes_count;
int fuel_count = 3;

Dashboard dashboard;
Aero aero;
Ground ground;
Arrow arrow;
Cannon cannon[30];
Volcano volcano[30];
Smokering ring[30];
Parachutes parachutes[30];
Fueltank fuel[10];
Shoot shoot;
Drop drop;
Ball ball;
Bullet bullet[30];
Fly_bullet fly_bullet[30];

Timer bullet_life(5);
Timer flybullet_life(4);
float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
int score = 0;
int lives = 5;
int prev_can;

Display altitude;
Display Score;
Timer t60(1.0 / 60);
bool view_top;
bool view_plane;
bool view_tower;
bool view_cam;
bool view_helicopter;

float eye_x = 0;
float eye_y = 0;
float eye_z = 5; 
float target_x = 0;
float target_y = 0;
float target_z = 0; 
float hel_x = -100;
float hel_y = 50;

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    if(view_top)
    {
        eye_x = aero.position.x;
        eye_y = aero.position.y + 20;
        eye_z = aero.position.z;
    
        target_x = aero.position.x;
        target_y = aero.position.y;
        target_z = aero.position.z + 1;
    }

    if(view_plane)
    {
        eye_x = aero.position.x;
        eye_y = aero.position.y;
        eye_z = aero.position.z -2;

        target_x = aero.position.x;
        target_y = aero.position.y;
        target_z = aero.position.z - 3;
    }

    if(view_tower)
    {
        eye_x = 50;
        eye_y = 50;
        eye_z = 50;

        target_x = aero.position.x;
        target_y = aero.position.y;
        target_z = aero.position.z;
    }

    if(view_cam)
    {
        eye_x = aero.position.x;
        eye_y = aero.position.y + 3;
        eye_z = aero.position.z + 20;

        target_x = aero.position.x;
        target_y = aero.position.y;
        target_z = aero.position.z + 1.5;
    }

    if(view_helicopter)
    {
        eye_x = hel_x;
        eye_y = hel_y;
        eye_z = 50;
    }

    // Eye - Location of camera. Don't change unless you are sure!!
    // glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 10, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    glm::vec3 eye (eye_x,eye_y,eye_z);
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (target_x, target_y, target_z);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);
    if(view_top) up.y *= -1;

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    //  Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;
    glm::mat4 VP1 = Trial.projection *glm::lookAt(glm::vec3(0,0,3), glm::vec3(0,0,0), glm::vec3(0,1,0));

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    ground.draw(VP);

    for(int i = 0; i < cannon_count; i++)
        if(cannon[i].alive)
            cannon[i].draw(VP);

    for(int i = 0; i<bullet_count; i++)
        if(bullet[i].alive && cannon[i].alive)
            bullet[i].draw(VP);
    
    for(int i = 0; i < volcano_count; i++)    
        volcano[i].draw(VP);

    for(int i = 0; i < ring_count; i++)    
        ring[i].draw(VP);
    
    for(int i = 0; i < parachutes_count; i++)
        if(parachutes[i].alive)
            parachutes[i].draw(VP);

    for(int i = 0; i<flybullet_count; i++)
        if(fly_bullet[i].alive && parachutes[i].alive)
            fly_bullet[i].draw(VP);    
    
    for(int i = 0; i<fuel_count; i++)
        if(fuel[i].alive)
            fuel[i].draw(VP);
    
    if(ball.alive){
        ball.draw(VP);
    }
    
    if(shoot.alive){
        shoot.draw(VP);
    }

    if(drop.alive){
        drop.draw(VP);
    }

    arrow.draw(VP);
    aero.draw(VP);
    dashboard.draw(VP1);
    altitude.draw(VP1);
    Score.draw(VP1);
}

void tick_input(GLFWwindow *window) {

    //views
    int plane = glfwGetKey(window, GLFW_KEY_1);
    int top  = glfwGetKey(window, GLFW_KEY_2);
    int tower = glfwGetKey(window, GLFW_KEY_3);
    int follow_cam = glfwGetKey(window, GLFW_KEY_4);
    int helicopter = glfwGetKey(window, GLFW_KEY_5);

    //aero movement
    int left  = glfwGetKey(window, GLFW_KEY_Q);
    int right = glfwGetKey(window, GLFW_KEY_E);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    int frwd = glfwGetKey(window, GLFW_KEY_W);
    int tilt_right = glfwGetKey(window, GLFW_KEY_D);
    int tilt_left = glfwGetKey(window, GLFW_KEY_A);
    
    //weapons
    int missile = glfwGetKey(window, GLFW_KEY_F);
    int bomb    = glfwGetKey(window, GLFW_KEY_G);

    if(top)
    {
        view_top = 1;
        view_plane = 0;
        view_tower = 0;
        view_cam = 0;
        view_helicopter = 0;
    }
    if(plane)
    {
        view_top = 0;
        view_plane = 1;
        view_tower = 0;
        view_cam = 0;
        view_helicopter = 0;
    }
    if(tower)
    {
        view_top = 0;
        view_plane = 0;
        view_tower = 1;
        view_cam = 0;
        view_helicopter = 0;
    }
    if(follow_cam)
    {
        view_top = 0;
        view_plane = 0;
        view_tower = 0;
        view_cam = 1;
        view_helicopter = 0;
    }
    if(helicopter)
    {
        view_top = 0;
        view_plane = 0;
        view_tower = 0;
        view_cam = 0;
        view_helicopter = 1;
    }
    if(left){
        dashboard.t1 = 4;
        dashboard.fuel -= 0.015;
        dashboard.rotation += 0.5;
        aero.roll = 1;
        aero.rotation_y += 0.5;
        aero.lefttick();
        shoot.rotation += 0.45;
    }
   
    if(right)
    {
        dashboard.t1 = 5;
        dashboard.fuel -= 0.015;
        dashboard.rotation -= 0.5;
        aero.roll = 1;
        aero.rotation_y -= 0.5;
        aero.righttick();
        shoot.rotation -= 0.45;
    }

    if(frwd)
    {
        dashboard.t1 = 6;
        dashboard.fuel -= 0.015;
        aero.yaw = 0;
        aero.frwdtick();
    }

    if(tilt_left)
    {
        dashboard.t1 = 3;
        dashboard.fuel -= 0.015;
        aero.yaw = 1;
        aero.rotation_z += 0.5;
        aero.lttick();
    }

    if(tilt_right)
    {
        dashboard.t1 = 3;
        dashboard.fuel -= 0.015;
        aero.yaw = 1;
        aero.rotation_z -= 0.5;
        aero.rttick();
    }

    if(down)
    {
        dashboard.t1 = 1;
        dashboard.fuel -= 0.015;
        aero.pitch = 1;
        aero.downtick();
    }

    if(up)
    {
        dashboard.t1 = 2;
        dashboard.fuel -= 0.015;
        aero.pitch = 1;
        aero.uptick();
    }

    if(aero.position.y <=  0 || dashboard.fuel == 0)
    {
        lives -= 1;
        aero.position.x = 0;
        aero.position.y = 3;
        aero.position.z = 0;
    }

    if (missile){
        shoot.alive = 1;
        shoot.position.x = aero.position.x;
        shoot.position.y = aero.position.y;
        shoot.position.z = aero.position.z;    
    }

    if(shoot.position.y < 0)
    {    
        shoot.alive = 0;
        shoot.yspeed = 0;
    }

    if (bomb){
        drop.alive = 1;
        drop.position.x = aero.position.x;
        drop.position.y = aero.position.y;
        drop.position.z = aero.position.z;    
    }

    if(drop.position.y < 0)
    {    
        drop.alive = 0;
        drop.yspeed = 0;
    }

    for(int i = 0; i< volcano_count; i++)
    {
        if(detect_collision(volcano[i].getboundingbox(), aero.getboundingbox()) && !volcano[i].killed)
        {
            lives -= 1;
            volcano[i].killed = 1;
            aero.position.x = 0;
            aero.position.y = 3;
            aero.position.z = 0; 
        }
    }

    for(int i = 0; i< ring_count; i++)
    {
        if(detect_collision(ring[i].getboundingbox(), aero.getboundingbox()) && !ring[i].killed)
        {
            score += 75;
            ring[i].killed = 1;
        }
    }

    for(int i =0; i< cannon_count; i++)
    {
        if(detect_collision(cannon[i].getboundingbox(), aero.getboundingbox()) && cannon[i].alive && !cannon[i].killed)
        {
            cannon[i].killed = 1; 
            lives -= 1;   
            aero.position.x = 0;
            aero.position.y = 3;
            aero.position.z = 0;         
        }

        if(detect_collision(cannon[i].getboundingbox(), shoot.getboundingbox()) && cannon[i].alive && shoot.alive)
        {
            cannon[i].alive = 0;
            score += 20;
            shoot.alive = 0;
            shoot.yspeed = 0;
        }

        if(detect_collision(cannon[i].getboundingbox(), drop.getboundingbox()) && cannon[i].alive && drop.alive)
        {
            cannon[i].alive = 0;
            score += 20;
            shoot.alive = 0;
            shoot.yspeed = 0;
        }
    }
    
    for(int i =0; i< bullet_count; i++)
    {
        if(bullet[i].position.y > 10)
        {    
            bullet[i].alive = 0;
        }
        if(detect_collision(bullet[i].getboundingbox(), aero.getboundingbox()) && bullet[i].alive)
        {
            lives -= 1;
            bullet[i].alive = 0;
        }
    }
    
    for(int i =0; i< parachutes_count; i++)
    {   
        if(detect_collision(parachutes[i].getboundingbox(), aero.getboundingbox()) && parachutes[i].alive && !parachutes[i].killed)
        {
            parachutes[i].killed = 1;
            lives -= 1;
            aero.position.x = 0;
            aero.position.y = 3;
            aero.position.z = 0;            
        }

        if(detect_collision(parachutes[i].getboundingbox(), shoot.getboundingbox()) && parachutes[i].alive && shoot.alive)
        {
            parachutes[i].alive = 0;
            score += 50;
            shoot.alive = 0;
            shoot.yspeed = 0;
        }

        if(detect_collision(parachutes[i].getboundingbox(), drop.getboundingbox()) && parachutes[i].alive && drop.alive)
        {
            parachutes[i].alive = 0;
            score += 50;
            shoot.alive = 0;
            shoot.yspeed = 0;
        }
    }

    for(int i =0; i< flybullet_count; i++)
    {
        if(fly_bullet[i].position.x > 10)
        {    
            fly_bullet[i].alive = 0;
        }
        if(detect_collision(fly_bullet[i].getboundingbox(), aero.getboundingbox()) && fly_bullet[i].alive)
        {
            lives -= 1;
            fly_bullet[i].alive = 0;
        }
    }

    for(int i = 0; i< fuel_count; i++)
    {
        if(detect_collision(fuel[i].getboundingbox(), aero.getboundingbox()) && fuel[i].alive)
        {
            dashboard.fuel = 50;
            fuel[i].alive = 0;
        }
    }

    if(detect_collision(ball.getboundingbox(), aero.getboundingbox()) && ball.alive)
    {
        lives += 1;
        ball.alive = 0;
    }
}

void tick_elements() { 
    ground.tick();
    for(int i =0 ; i< cannon_count; i++)
        cannon[i].tick();
    for(int i =0 ; i< parachutes_count; i++)
        parachutes[i].tick();    
    for(int i =0 ; i< fuel_count; i++)
        fuel[i].tick();
    camera_rotation_angle += 1;
}

void Levelup(){
    
    if(lives == 0)
    {
        cout<<"YOUR SCORE :"<<score<<"\nGAME OVER";
        cout<<"lives"<<lives;
        quit(window);
    }
    if(score > 200)
    {
        cout<<"MISSION COMPLETED!!! \n"<<"YOUR SCORE"<<score;
        cout<<"lives"<<lives;
        quit(window);
    }
}
/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    int j,k,l,m,s,t,p,q; 
    j =k = l = m = s = t =p =q =1;

    ground       = Ground(0, 0, 0, COLOR_LIGHT_BLUE);
    aero         = Aero(0, 3, 0, COLOR_BLACK);
    arrow        = Arrow(aero.position.x, aero.position.y + 1, aero.position.z - 2.5, COLOR_DARK_RED);
    dashboard    = Dashboard(-3.5, -3.25, -10, COLOR_YELLOW);
    altitude     = Display(-0.5, 3.29, 0);
    Score        = Display(-7, 3.29, 0);
    
    for(int i = 0; i < cannon_count; i++){
        l *= -1;
       cannon[i] = Cannon(10*j*l, 0, -5*j, COLOR_DARK_RED);
        j++;
    }

    for(int i = 0; i < bullet_count; i++){
        bullet[i]= Bullet(cannon[i].position.x, cannon[i].position.y + 0.5, cannon[i].position.z, COLOR_DARK_BLACK);
    }

    for(int i = 0; i < volcano_count; i++){
        m *= -1;
       volcano[i]= Volcano(5*k*m, 0.3, -rand()%120, COLOR_PURPLE);
        k++;
    }

    for(int i = 0; i < ring_count; i++){
        p *=-1;
        ring[i]= Smokering(9*p*q, rand()%3 + 3, -9*q, COLOR_BLACK);
        q++;
    }

    for(int i = 0; i < parachutes_count; i++){
        s *= -1;
       parachutes[i] = Parachutes(7 * s * t, 5, -17*t, COLOR_BLUE);
        t++;
    }

    for(int i = 0; i < flybullet_count; i++){
        fly_bullet[i]= Fly_bullet(parachutes[i].position.x + 0.5, parachutes[i].position.y, parachutes[i].position.z, COLOR_DARK_RED);
    }

    fuel[0] = Fueltank(-30, 5, -10, COLOR_GREEN);
    fuel[1] = Fueltank(40, 8, -20, COLOR_GREEN);
    fuel[2] = Fueltank(50, 3, -15, COLOR_GREEN);

    ball    = Ball(10, 10,-20,COLOR_DARK_RED);

    shoot       = Shoot(aero.position.x, aero.position.y, aero.position.z, COLOR_BLUE);
    drop        = Drop(aero.position.x, aero.position.y, aero.position.z, COLOR_RED);

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Trial.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}

void checkpoint(){
    for(int i =0 ;i< cannon_count; i++)
        if(cannon[i].alive)
        {
            cannon[i].arrow = 1;
            if((i%2)==0)
                arrow.lefttick();
            else
                arrow.righttick();
            prev_can = i;
            break;
        }
}

int main(int argc, char **argv) {
    srand(time(0));
    int width  = 600;
    int height = 600;
    char score_disp[1000];
    double xpos, ypos;

    window = initGLFW(width, height);

    initGL (window, width, height);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

     // Set the mouse at the center of the screen
    glfwSetCursorPos(window, 2, 250);

    cannon[0].arrow = 1;
    arrow.rotation += 10 ;
    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            altitude.update(aero.position.y);
            Score.update(score);

            sprintf(score_disp, "Lives %d", lives);
            glfwSetWindowTitle(window, score_disp);
            
            //helicopter cam pos
            glfwGetCursorPos(window, &xpos, &ypos);
            hel_x =float(xpos);
            hel_y =float(ypos);

            //arrow pos
            arrow.position.x = aero.position.x;
            arrow.position.y = aero.position.y + 1.0;
            arrow.position.z = aero.position.z - 2.5;
            
            //checkpoint pos
            if(!cannon[prev_can].alive)    
                checkpoint();            
            
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);
            
            tick_elements();
            tick_input(window);

            Levelup();
        }

        if(bullet_life.processTick()){
            for(int i=0; i < bullet_count; i++){
                bullet[i].alive = 1;
                bullet[i].position.x = cannon[i].position.x;
                bullet[i].position.y = cannon[i].position.y + 0.5;
                bullet[i].position.z = cannon[i].position.z;
            }
        }

        if(flybullet_life.processTick()){
            for(int i=0; i < flybullet_count; i++){
                fly_bullet[i].alive = 1;
                fly_bullet[i].position.x = parachutes[i].position.x + 0.5;
                fly_bullet[i].position.y = parachutes[i].position.y;
                fly_bullet[i].position.z = parachutes[i].position.z;
            }
        }
        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height)) && (abs(a.z - b.z) * 2 < (a.depth + b.depth));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::perspective(glm::radians(30.0f), 1.0f, 0.1f, 500.0f);
    // Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
