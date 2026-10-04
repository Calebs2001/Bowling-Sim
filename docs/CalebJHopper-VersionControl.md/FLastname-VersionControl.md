# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ Project And Portfolio I: Computer Science - Lecture COS119-L 00]

- **[ Caleb Hopper]**
- **[ Oct 4, 2026 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ clear ]: Clear the Screen
- [ pwd ]: Print the "Working Directory"
- [ ls ]: List files and folders
- [ ls -a ]: List files and folders, including invisible files
- [ ls -lh ]: List all files and folders, in human readable form
- [ cd ]: Change directory
- [ cd / ]: Change directory, go to root directory
- [ cd ~ ]: Change directory and go to user home directory
- [ cd .. ]: Change directory, go up one folder level
- [ cd ../.. ]: Change directory, go up two folder levels
- [ cd ~/Desktop ]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ The terminal is now operating out of the file that I have entered and shows the full file path that I am currently in. ]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ Local: stores all file changes and history on one or multiple devices. Centralized: stores all project files and version history on a single central server. Distributed: gives every user a complete local copy of the entire project repository, including full change history.]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone [url] ]: Clone a repository
- [ git config --global user.name "[firstname lastname]" ]: Set-up a global user name
- [ git config --global user.email "[valid-email]" ]: Set-up a global email address (to match my GitHub account email)
- [ git status ]: Shows the current state of your directory and staging area
- [ git add [file] ]: Add modified files to the next commit
- [ git commit -m "[message]" ]: Make a commit with a new message
- [ git log ]: Show my commit history
- [ git help ]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ Open  the terminal, configure global Git profile by setting up a username and email using the git commands to do so.  Then take the Git url and run the git clone command. Click to authorize git-ecosystem and login to GItHub account. ]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [It tells Git to to ignore ceratian files to prevent them from being tracked so they wont be able to commit or be pushed.]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [It is used to store finder information. You wouldn't want to add it because it's contents can change without there being any interaction with the file.]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [You would want to include any API keys, passwords, or or credentials into the .gitignore file because those are sensitive and private information you wouldn't want just anyone to have public access to.]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ Research Summary: What resource(s) did you find most helpful this past week and why? ]

**Terminal Commands**  
[https://stackoverflow.com/questions/18704222/command-to-clear-the-git-bash-screen-including-output-buffer](https://stackoverflow.com/questions/18704222/command-to-clear-the-git-bash-screen-including-output-buffer)

[https://bash-intro.rsquaredacademy.com/navigating-files-and-directories](https://bash-intro.rsquaredacademy.com/navigating-files-and-directories)

[https://stackoverflow.com/questions/12198222/go-up-several-directories-in-linux](https://stackoverflow.com/questions/12198222/go-up-several-directories-in-linux)

[https://askubuntu.com/questions/373043/change-directory-command-to-desktop](https://askubuntu.com/questions/373043/change-directory-command-to-desktop)


**Three Types of Version Control**  
[[Site Address](https://www.geeksforgeeks.org/git/version-control-systems/)]([https://www.someaddress.com/full/url/](https://www.geeksforgeeks.org/git/version-control-systems/))

**Git Commands**  
[[Site Address](https://education.github.com/git-cheat-sheet-education.pdf)]([https://www.someaddress.com/full/url/](https://education.github.com/git-cheat-sheet-education.pdf))

**Connecting to GitHub using Terminal**  
[(https://coderefinery.github.io/installation/ssh/)]([https://www.someaddress.com/full/url/](https://coderefinery.github.io/installation/ssh/))

**Using .gitignore and Why it's Important**  
[(https://stackoverflow.com/questions/78525252/what-is-the-use-of-gitignore-in-a-github-repo)]([https://www.someaddress.com/full/url/](https://stackoverflow.com/questions/78525252/what-is-the-use-of-gitignore-in-a-github-repo))
