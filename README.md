## Execute:
1.Create a build folder(mkdir build)
2.cd into build folder(cd build)
3.run : cmake ..
4.run make all
5.compile ./graphic_asgn1

CONTROLS:
A/D- Rotate Plane counter clockwise/clockwise direction
Up/Down- Plane altitude increase and decrease
Q/E - Tilt Plane about it's own axis
W - Move plane forward
F - Plane shoot Missiles
G - Plane drops bombs
1 - PLane view
2 - top view
3 - Tower view
4 - Follow cam view
5 - Helicopter view 
Mouse scroll - zoom in and zoom out
Mouse button click- change the eye of the helicopter.

How Game Works?
-> Plane is guideed by the Arrow to the checkpoints.Once the checkpoint is destroyed, arrow points to next checkpoint .
-> Every checkpoint has enemy cannon attacking the plane by throwing cannon balls at plane.
-> There are smoke rings, when the plane passes through it gets bonus.
-> There are flying parachutes which shoot at plane , when collides with it losees lives.
-> Plane can fire or bomb at enemies using missiles and bombs.
-> There are volcanoes in the sea that is regarded as NO-FLYING zone.
-> Fuel UP for fueling the plane.
-> Have four views - Top , Plane, Follow cam, Tower, Helicopter.

OBJECTS:
->Sea
->Sky
->Plane
->Dashboard(speed, altitude, compass, fuel remaining)
->Checkpoints
->Cannon
->Volcacno
->Parachutes
->Fuel UP
->Missiles
->Bombs
->Cannnon balls
->Bullets
->Smoke rings
->Arrow
->Compass

FEATURES:
-> Implemented Game map(inludes ground and sea)
-> Plane movement(rotate, tilt, up, down, forward)
-> Plane shoot misiiles, throws bombs.
-> Dashboard(speed, altitude, compass, fuel remaining)
-> Can Zoom In/Out by mouse scroll.
-> Arrow guiding the plane.
-> Checkpoints with cannons attacking the plane.
-> Score display using 7 segment
-> Smoke rings for extra score.
-> Fuel up  to fuel the plane
-> Volcanoes on the islands.
-> shooting parachutes.
-> Plane view
-> Top view
-> Tower view
-> Follow cam view
-> Helicopter view

BONUS:
->Implemented Compass.
->Aero Plane can perform special manoeuvres like looping-the-loop or a barrel roll.
->pecial obstacle on air when collected gives extra lives.
