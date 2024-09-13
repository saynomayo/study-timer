# study-timer
This study timer requires a Raspberry Pi 4 or above and the SenseHAT attachment. Required libraries are within the repository.

This project is still in progress but currently has the base functionality! I will be adding "styles" (i.e. different ways to display the time) soon.

**This may consist of display styles that are indicative of the time left, or something like LEDs on the SenseHAT array clearing one at a time.**

# current functionality "flow"
   ![Screenshot 2024-09-03 000814](https://github.com/user-attachments/assets/4100abfd-41cc-4fdb-9b74-1dd3792294a8)

# how to compile
Simply run Make All in the terminal! (must be in the same directory as the project)

# how to run
Either run ./timer in the terminal or Make run.

# adjust time
  Up and down on start up to adjust minutes
  Right or click in on joystick to switch to seconds
  You can go back to the minutes setting by pressing left on the joystick
  Confirm decisions by clicking in on the joystick. You can also think of clicking in on the joystick as moving to the next state.

# reset timer
  Holding the joystick in while the timer is running will rapidly decrease the time. You can do this to bring the time down / close to 00:00.

# change colors
  while the timer is running, push the joystick left/right to change color themes.

# change style (not yet implemented)
  ~~while the timer is running, push joystick up/down to change visual mode.~~


