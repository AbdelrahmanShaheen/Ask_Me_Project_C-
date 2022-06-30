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
* Login

![login](https://user-images.githubusercontent.com/77184432/176609043-74a5c95a-0686-479b-b589-f6f389070b36.png)
* Print Questions to me

![Print-questions-to-me](https://user-images.githubusercontent.com/77184432/176609225-4028ceb0-e838-4a09-865f-d7bb34cccc62.png)
* Print Questions from me

![print-questions-from-me](https://user-images.githubusercontent.com/77184432/176609311-3d0d6838-6b8c-482a-82b2-78ff6906aa7d.png)
* Answer and Delete

![answer-and-delete-questions](https://user-images.githubusercontent.com/77184432/176609430-8c6f26a1-9698-4134-a728-751f32348927.png)
* Updated system

![update-system](https://user-images.githubusercontent.com/77184432/176609542-17bddff8-fc7c-4e5d-a6a2-e8b59e2e107a.png)
* Listing system users

![listing system users](https://user-images.githubusercontent.com/77184432/176609632-3f5046f1-2fe5-4a55-9595-59d445bc3679.png)
* Ask question, not a thread

![asking question not a thread](https://user-images.githubusercontent.com/77184432/176609758-d82e43c3-b6b8-49fe-9c82-d6beaee1167c.png)
* Ask question, in a thread

![ask question in a thread](https://user-images.githubusercontent.com/77184432/176609902-65d05356-1edc-4be6-b79c-2b63f199df09.png)
* Listing the users feed

![listing users feed](https://user-images.githubusercontent.com/77184432/176609995-eef3f6b8-a2cd-4bff-87d1-c29af4f92502.png)
* login by Noha user

![loging by another user](https://user-images.githubusercontent.com/77184432/176610183-fb29b01a-d1ca-452c-8f42-0eb6d0c058e9.png)
* Sign up

![signup an account](https://user-images.githubusercontent.com/77184432/176610292-cab690b2-99e9-438c-b298-e8fe229192be.png)

## Technologies used:
* only c++ , its a console app for learning purpose.

