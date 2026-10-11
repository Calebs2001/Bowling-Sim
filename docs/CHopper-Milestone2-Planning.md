> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name:**
→   Bowling Sim
  
**What does your program currently do? (1–3 sentences)**   
→ Currently my program gets the user's input for if they want to start a new game, practice, look at the leaderboard, or quit. When they choose to play the game gets their name, if they are left or right handed, and then if they want to choose a ball or quit back to the menu. When the user chooses to select a ball they then choose the ball they want to throw, how to throw it, then the ball is thrown an knocks down pins letting them know how many they hit for each frame.

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   Right now the Pin and PinSet classes are completed, as well as the Bowler class, Scorecard class, Frames class, and Roll class.
  
**What is NOT working or incomplete?**   
→   Right now the Game class is not complete because it has some UI fixes that it needs, some user input validation fixes are needed. The Ball class is incomplete because of a future feature I would like to add where oil can get on the ball and lower its chance of striking or getting a spare.
  
**What feels confusing or messy in your code?**   
→ I think inside the Game class, the PlayFrame and SimulateRoll functions are a little messy and could be cleaned up a bit to look a play a little nicer.

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   
→   Wipe Oil Off Ball
  
**What does this feature do?**   
→   As oil accumulates on the ball from each throw it lowers its chance to strike or spare. Wiping the oil off the ball would increase it's chance back to it's original chance percentage, unless it is the Urethane ball then it only increases back partly
  
**Why is this feature important?**   
→   It will add more variety to the game and more consequence if the user doesn't learn the cleaning the ball is important.
  
---
### Feature 2  
**Name:**   
→   Max Score
  
**What does this feature do?**   
→   After each time the user rolls the ball, next to the scorecard it will display the possible maximum score out of 300 the user could still possibly get.
  
**Why is this feature important?**   
→   It will make the user want to keep playing and challenge themselves to try and reach that max score, especially if they see that they could possibly get a perfect score.
  
---
  
### Feature 3 (optional)  
**Name:**   
→   
  
**What does this feature do?**   
→   
  
**Why is this feature important?**   
→   
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   I might need to create a oil or lane class that contains the oil
  
**Will you modify any existing classes? How?**   
→   If I don't need to make a new class for the oil, I would probably have to add it to the Ball or Roll class and have it interact with the percentages that were given to each ball in the Game class.
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   I will be using a vector that will keep track how many times the ball has been thrown and based on the size of the vector the lower the chance of striking or getting a spare.
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   The menu shows up prompting the user to select a number 1-4 to start game, practice, leaderboard, or exit.
2. User chooses →   1
3. Program responds →   The program then prompts the user to input their name.
4. Loop/next step →   The program then asks the user to input a number 1-2 if the bowl with their left and or their right hand.
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   I am giving the user directions on what input is a valid input for them by stating for them to choose a number 1 through whatever number of selections there are.
  
- Better error handling:   
→   I was doing only if or else if statements but that was braking the game if the user input a letter when it expected a number. So I have added in a catch all statement so that no matter what the user inputs, it doesn't break the game.
  
- Improved menu/navigation:   
→   The menu needs to reset when the user makes an invalid input, and when the user chooses to quit back to the menu. It currently shows the previous put in information, and functions from later on text output.
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   The hardest part this week will be debugging any UI problems that I am having since there is a lot of code that goes through the Game.cpp file.
  
**What is your plan if you get stuck?**   
→   My plan is to take a break for a few minutes and think on it before coming back to fix the issue. If I still get stuck I will ask a question in the Discord stating the things I have done and have tried and if I can get help in being pointed in the right direction.
  
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→   This week I was leveling up on creating catch all methods for user verification.
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   I will be running the program and testing each prompt where a user input is required with multiple inputs to test and debug the catch all method to ensure it is working.
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [ ]   Improve user validation
- [ ]   Improve game UI
- [ ]   Add File I/O
- [ ]   Add Oil Class/Function
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [ ] Do I know what I’m building this week?   
- [ ] Do I know where to start?   
- [ ] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> Plan it now… or debug it later.