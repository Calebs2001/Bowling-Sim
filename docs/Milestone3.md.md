
## Development
-⚙️ Additional features implemented based on your plan
I have implemented the score multiplier feature so that when the user gets a spare the next frame adds its score to the previous frame, and a strike adds the next 2 frames or 2 throws to its frame. This brings the games total possible score from 100 up to 300 just like it is in real 10 pin bowling. There was also a 3rd throw added to the 10th frame if the user gets a second strike in the 10th frame or a spare on their second throw.


-🧱 Expansion of your system's functionality
For the CleanBall() function as the user throws a ball, that ball builds up oil making it less effective when hooking. To make it go back to its original stats for getting a strike or spare when hooking they must clean the ball. The only ball that doesn't go fully back to it's original stats when cleaned is the Urethane ball

AddOil() is used to add 10 percent of oil to the ball which affects the balls hooking status.

The Input helper and GetNumber() function was added to improve user input validation. The function only accepts a input of integers and is used to set the valid min and max rang of what inputs are valid, and if the input is out of range it continues to have the user retry to input a valid option.


-🔧 Ongoing improvements to your program structure
Game UI is still in need of improvements , and adding better structure to make the code more readable so you know exactly where to go and where things are if any code needs to be fixed or adjusted and improved on. I think there are a lot of methods that just need to be moved around into a block for just methods, and then the functions where parts of the game are played have their own block. Currently the function and methods are with their corresponding functions, aside for maybe some new added functions that were added after the base game was completed.


-🧪 Continued testing and debugging
I have continued to constantly test the game after each new feature has been added, and after refactoring sections of my code. I have also been having my friends play test my game and get their inputs and let them try to brake the game.



# Documentation
⚙️ Features added
I have added a AddOil() and CleanBall() feature where the ball gains oil making it less effective when hooking unless the user chooses to clean the ball. I have also added in a second user verification if the user accidentally chooses to exit back to the menu, if not the they choose to exit back to the menu again.


🧱 Updates to your system design

I have included a exit to menu verification and colored anything that would end the players game or quit the program in red so the user knows that red means bad or quit. And I have color coded game changing selections yellow and the results of those chances also yellow at the end of the game. Anything that does not alter that is just info to the user while they play is cyan. And anything positive or that the user may want to do instead incase of a miss-input is colored green.

 🧹 Refactoring improvements

The Ball class now keeps track of the ball's selected and used by the user. It was previously being tracked by the Roll class. There was also a problem where Roll would create and then delete the ball after each roll, so a new ball would be created each time. This would remove the oil added to the ball just thrown. So if Pearl was thrown, then chosen to be thrown again, there would be no oil on the ball. So now Ball has to store and track the ball thrown so the oil can stay on the ball then be removed when the user chooses to clean the ball.

I also went on to refactor the ScoreCard class function called Display() to show how many pins the user knocked down for each roll, the total score from each frame to the next to show how their score adds up, and if their frame was a strike or spare.

Created a EnterClearScreen() function

Created a ClearScreen() function

 💭 What you changed and why
 I've made these changes because some of them were required for a feature that was newly added. But also for ones like EnterClearScreen() and ClearScreen() just for there to be less lines of code in a function, and it helps make it clear what is happening in that line of code.