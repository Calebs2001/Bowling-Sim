Final features added:
I added in a few ASCII art features to draw a sign for a strike, a sign for a spare, a sign for a gutter ball, and updated the scoreboard. I also added in a SaveScore() feature to save the user's name and score when they finish the game, and to display it when the user goes to ShowLeaderboard().

Refactoring improvements:
I had to refactor PlayFrames() to become a bool, so that only if the user finished playing their score would be saved, and if they quit mid way through their score does not save.

Bug fixes:
A bug I had was with the ASCII art for the scoreboard. The score of pins that were hit were being added to a char character giving an incorrect score on the display. And anytime a new ammount of characters were added the scoreboard would become unaligned.

Usability updates:
I have improved the UI for the user to see the colors to help separate text from each other, and to add in specific prompts on what the users options are.