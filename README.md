# 🚀 Welcome to Project & Portfolio!

This repository will be used to keep track of research and development conducted in this class. Follow the instructions below to get started.
cos
### Getting Started

**1.** Review the [About](./docs/01_about/README.md) README and all of the links it provides.

**2.** Review the documentation and [Getting Started](./docs/02_getting_started/README.md) steps in this repository's docs folder.

**3.** Attend the first Live Lecture to see a live setup demo. If you are unable to attend, make sure to watch the archive.

### Next Steps...

After completing the above steps, feel free to begin updating this readme where indicated below. Remember to update this document each week to receive proper credit for the weekly Milestone assignment.

<br>

> ❗️ &nbsp; Now that you have read to this point, go ahead and delete this sentence and everything above it.

<br>

# Project & Portfolio 1

### Student First & Last Name

Hello my name is [Caleb Hopper]. I am a student from [Deltona Florida]. The purpose of this repository is to practice development using version control. This work will help me begin to build a portfolio of skills and accomplishment that can be shared in the future.

<br>

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

⚙️ Overview - What I worked on this past week
<br>
🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - What is something I "leveled up" on this week
<br>
🔮 Next Steps - What I plan to prioritize and do next

<br>

### Week 1

Progress Update: I have came up with all the required files and classes that my game will require. I have started working on creating the Game class and will next create the interactive menu. Next I plan to work on the Pin class and PinSet class. The only problem I have encountered so far was knowing just what classes I would need. There are other ideas I have for my game but will add them to the backlog once I have a working version of the game. Experience Reflection: I've had a lot of fun getting to think of the key features that are required to create my game. Using GitHub Issues and Project board is helping me visually as to what I need to do and where I am at. The resource I have used so far is ChatGPT just to help me with what classes I need. I knew I needed a Game class, Bowler class, Ball class, and a class for the pins. But I didn't know I would need a class for each individual pin and one for all of the pins. Focus Area: This month I want to focus on using pointers and practicing with them in my project. since I still struggle with knowing when and where to use pointers even though I know how they work and how to use them.

End-of-Week Stand-up: This wee I have worked on the interactive menu, and created all of the required classes and their base functions to run the game. I've been able to create the Pin and PinSet class and successfully test them .A challenge I have faced so far is that there were more functions than I originally thought I would need in order to have the game be playable. I've have improved on being able to read an error and figure out where the problem is to debug my code. The next step before the next milestone is to fix the infinite loop when you try to play the game that is located in the Scorecard or Frames class, to play test the game, and add more variety to the Ball class.

### Week 2

Progress Update: So far this week for my Bowling Sim game I have worked on adding functions required for the game to run and be playable, and getting user input to work. I have also done some debugging to fix a infinite loop that was located in my Scorecard class. Right now I am adding in user input that takes in what ball the user would like to throw, how they want to throw it, and also getting what hand the user throws with. I also want to get started on working on adding different chances of different balls hitting pins and getting strikes or spares. Some challenges I have faced this week is needing to add more functions to my Game class to simulate the game. Another challenge is also that if you don't get a strike the user gets a second roll, and I have to go back to the user selecting what they want to do while still remaining in that one frame but second throw and its choices again, then moving onto the next frame. Project Progress: The feature I am showing is the user being able to choose to throw and how to throw, while also giving them the option to quit back to the menu at any frame. And then when they have a second throw it looping back for them to choose what they want to do again before advancing to the next frame. Usability Improvements: I am making my program more user friendly by being very clear on what buttons or inputs are available for them to use. I also do have user input validation to try and nudge the user into doing exactly what the prompt says. Another usability improvement I am working on for when playing the game is clearing the screen after each throw so the screen doesn't become crowded with multiple old prompts and inputs. Level Up Goal: This week I would like to improve on using "catch" for my user input validation instead of using get.ignore() or cin.get() or system("cls"). I will be using the example that was provided to use in class on Monday to change my user input validation areas and update them.

End of week standup
	Overview – What did you work on this past week? This past week I have worked on adding in better user input validation using that catch all method. And I have also added in the different chances of different bowling balls to get a strike or a spare, and add in that hooking or bowling the ball straight could increase its chance as well. I have even added in a randomly generated seed so that the game doesn't always have the same outcome. 
	
	Challenges – What obstacles did you encounter, and how are you addressing them? This week the biggest challenge I have faced is being sick and not having the energy or brain power to do as much coding as I would like, or be able to do as much problem solving for the bugs and issues I have encountered along the way. I have also struggled with some UI problems when choosing to return to the menu but the game has the other functions still print out their text.
	
	 Accomplishments – What is something you learned, improved, or "leveled up" on this week? This week I have leveled up on knowing how to use a catch all and how to use it. I had it in once place when testing and it worked. But then saw another area that would need it that was causing problems when I put in other inputs. The first catch all was in a switch statement, but I also learned that it's the pretty much the exact same thing for a if and if else statement. 
	 
	 Next Steps – What do you plan to prioritize before Week 3? For the next week I would like to prioritize UI design and adding in more ASCII art, and then also fixing any remaining bugs. And if there are any other places I missed adding in a catch all user input validation.

### Week 3

Progress Update: Since last week I have completed fixing the game screen clearing back to the menu after the game ends or when quitting mid game. I have also added in score multiplying. Had to completely replace the GetTotalScore() to get the scores to multiply if a strike or spare is made so the score can go up to 300. Currently I am working on updating the Display() function for Scorecard to show the number of pins knocked in each frame, if it was a spare or strike that frame, and the score for that frame. It currently only shows the number of pins knocked that frame. This week I still need to accomplish improving user input validation at every area that requires user input. A bug/challenge I have encountered is that after updating the GetTotalScore() function the score was not updating as the user played through the frames. I found that everything was being stored but not being displayed. Refactoring Plan: One are that needs refactoring is the area I described above. Display() for the Scorecard only shows the total number of pins knocked down. It doesn't show the number of pins for the first or second throw, and it doesn't show the score from that frame if bonuses were added, or where the score was at for that frame, and if the frame was a spare or strike. Anther thing I need to refactor is user choice verification. It is very easy for the user to accidentally quit playing the game, so I need to add in a "Are you sure you want to quit?" prompt. Level Up Goal: This week I wan to level up on Refactoring. I think there are a lot of existing features that need to be adjusted or improved on. I will continue to play test the game and find areas where a function is lacking usability or if it has code that isn't needed.

 Overview – What did you work on this past week? This week I worked on updating the Display() function to show the total number of pins knocked down in a frame, along with the total score from that frame, and if it was a strike or spare. I have also worked on adding the CleanBall() function to give the user more choices to change up the flow of the game. 
 
  Improvements – What changes, refinements, or new features did you make? Some refactoring I have done is adding the ClearScreen() and EnterClear() method to make some code in the functions look a little less cluttered. I also made the changes that I described earlier for the Display() function 
  
  Challenges – What obstacles did you encounter, and how are you addressing them? An obstacle I encountered this week was encountering build errors and having to debug when refactoring the Display() function for my scorecard. One problem was that the scorecard wasn't updating after a throw or even a few throws. So I had to add some debugging code that would output the number of pins during the throw, and then got to the end of the scorecard and see that everything was being stored to find where my problem was. 
  
  Feedback – What feedback have you received, and how will it influence your next steps? Some feedback I have received feedback to add ASCII art to my project that is themed around bowling. I have a few ideas. 
  
  Next Steps – What is your primary goal for Week 4? My primary goal for this week is to improve the UI and adding ASCII art. I will also be testing the game more extensively.

### Week 4

This week I have accomplished getting all the ASCII art I needed, improving some of the games UI, and added in file I/O so now that the ShowLeaderboard() function works. I polished up the Display() method in the Scorecard class to look and act like the scorecards at real bowling alleys. I also polished PlayFrames() function in the Game class so to be a bool so that if the user finishes the game then the score and name are saved for the leaderboard. The biggest challenge for was learning how to use pointers and where they needed to go, because as the project grew, where the address of things were and what needed to be pointed to change. So I had to do some research and have some things explained to me as to why I was having to change or move my pointers. My biggest takeaway from this class is the importance of time management, how to use a project board, do pull and merge requests, and How to have multiple branches of classes interact with each other. If I continue this project I would like to add in that the user can select where to throw the ball from on the lane, and maybe add in different oil patterns.
