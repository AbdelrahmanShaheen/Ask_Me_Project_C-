# This is an **AskMe system project** using `classes` for encapsulation.
 This is a simulation of ask.fm site as We all familiar with the ask.fm site ,where people ask questions and others answers them.

## Feauters
* This is files-based system
   * Data Stored in two files ,one for questions(questions.txt) and the other for users(users.txt)
   * These two files in a folder called "DataBase" above.
  
* Login/Sign up/Sign Out
   * Any system allow a user to sign up (name, email, password, username, password)
   * You can loggin with (userName ,password)

## operations :
* ```User operations``` :
  * Print questions: From you, To you, Feed Questions
  * Ask and answer questions. System support threads
  * Delete a question (which might be a thread)

## Design :
* Every user has a system generated ID
   * Same for every question
   * We can view these IDs on the site (not realistic)
* A thread question
   * If a question is answered. Others can ask questions in the original question thread
   * E.g. original question is parent for all of them
   * If this parent question is removed, the whole thread is removed  
* Correctness
   *  You can’t do something wrong!
   *  E.g. you can’t remove a question asked to someone else!
   *  You can only see/edit the details of your question
## App Architecture
**It's not the exact architecture ,but it's very near to it and it will clear the flow of the app**
* Using oop paradigm
* applying these concepts : encapsulation ,Single responsibility , DRY and composition.

![App-Architecture](https://user-images.githubusercontent.com/77184432/176608566-18b1e12f-97ad-410a-a03d-ace876e10f07.png)

## Screenshots


## Technologies used:
* only c++ , its a console app for learning purpose.

