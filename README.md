# BootlegFrogger
CSE165 Final Project

To do:

Create a "Frogger.cpp" or "Game.cpp" file with a corresponding .h that privately inherits from "Timer".
(Using the template, this is accomplished.)

Figure out a structure for the objects that are going to be used.
- Different types of vehicles/obstacles (spawn location, spawn rate)
- The player controlled frog (distances, animations, speed, etc...)
- The GUI for the time remaining and lives left 
- How the board is set up (either a grid, or just a bunch of designated rows, etc...)
- Endgame/Goal (Simply to get to the next level, fill all 4 spots, indefinite, etc...)

Game Structure:
- Creating the player frog
- Create the gui
- Create the map (done)
- Split the map into a number of rows, most likely 12. 1 at the start (safe), 5 on the road, 1 in the middle (safe), 4-5 in the river, and 1 more as the goal.  (done)
- Perhaps use class to dictate how many TexRects/AnimatedRects are present at any given row. Possibly use an ID or some sort of number to know which row it belongs to make setting their y-axis easier. (done)
- Obviously, WASD or Arrow controls, no pause system cause fuck em.
- The goal will be comprised of separated textured rects, the actual endposts and the backrow which is just a decoration. To reach the end, the frog must succeed collision with an endpost. Once that endpost is taken, another frog may not succeed a collision check there and will result in death. (done)
Addendum: To simplify the game, the end goal is comprised of simple purple_tile TexRects and the goal is simply to get from one side to the other. No multiple levels or multiple frogs to win.

Frog/Player Character:
- The frog will use two (maybe three if North and South cannot be flipped) sprite sheets for all 4 compass orientations and animations corresponding with each. Frog_WE and Frog_NS will simply be flipped to correspond with the opposite orientation. 

Obstacles:
- On the road, the game will have predetermined routes for each row. It will go as follows; Row 1 utilizes the car_white asset and moves from left to right, Row 2 utilizes car_purple and moves right to left, Row 3 utilizes car_race and moves left to right, Row 4 utilizes car_yellow and moves left to right, Row 5 utilizes truck and moves right to left. Essentially, they are alternating row-wise, will only flow in one direction, and only one type of vehicle per row. The speeds of the vehicles will be determined based on the car asset used, such as the truck moving slower than the car_yellow and car_racecar moving faster than all.
- The log routes will be in a similar manner, with it comprising of; Row 1 with logs, Row 2 with floaty things, and alternating so forth until Row 4-5 right next to the goal. 
- Note: ("log" is interchangeable with "floaty thing" or simply "river obstacle"). There will need to be some sort of algorithm or check as to where the frog will snap onto the log after it succeeds the collision check, and the frog will need to move along with the log it's on. If using the floaty thing, the frog will not be allowed to step onto it and will fall if already on it.

GUI:
- Will use the provided font to display any text.
- Just have a small graphic to showcase the frog's lives.
- Perhaps a bar for the timer, if that is too complex then a text timer.

Endgame/Goal:
- The goal of the game will simply be to fill all 4 spots at the end. There will be no added difficulty or extra levels for simplicity sake.
- The player will lose a life if they run out of time, get run over, or fall into the river.
- The player will get a game over once they run out of lives.
- The player will be victorious and end once all 4 frog spots are filled.
