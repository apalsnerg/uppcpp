---------- OBJECTIVE ----------

The objective of this repository is to remotely host code and solutions produced by student Birk Höijer (biho23) during the course 1TD317 (Datorer och Programmering) at Uppsala University.



---------- GENERAL INFORMATION ----------

The solutions for each specific assignment of the course will be in their own folder. For example, the solution to the first assignment will be in the folder kmom01, the second in kmom02, and so on. This way, each solution remains independent, isolated, and organized.


---------- USAGE INSTRUCTIONS ----------

1. Open your git terminal.
    1a. If you do not have this program installed, get it from https://www.git-scm.com/downloads. Install instructions for your OS/Distro can be found there also.

2. Navigate to the directory where you would like to have the files.

3. Get the clone link to this repo by pressing the green "<> Code" button on GitHub. Copy the HTTPS link.

4. In your git terminal, enter the command "git clone [[ REPO LINK ]]".

5. If your desired file exists and is compiled, run it. It will usually be called "solution.exe".

-> IF FILE IS NOT COMPILED:

6. Ensure you have a C++ compiler installed. I recommend G++, but there are options. The following instructions are for G++ only.

Note: You have the option of deciding the name of your output file. If this is something you want, add "-o [[ DESIRED NAME ]]" after the "g++" part of the command.

7. In your command line/terminal, run the command "g++ [[ FILENAME ]]"

Note: Multiple files can and may be used in the compilation. Always check the main file and its included files to see which C++ files are required for the compilation. For example, if the program requires main.cpp, foo.cpp, and bar.cpp, you would run "g++ main.cpp foo.cpp bar.cpp". Of course, the note for step 6 still applies.

8. If all was successful, return to step 5. Else, make sure you followed the instructions correctly. If it still does not work, please create an issue describing the error and add your error message.
