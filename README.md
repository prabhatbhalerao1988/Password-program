Algorithm 
1-Initialize Stack:
       Set stack.top = -1.

2-Loop (Password Attempts):
       For attemptsLeft = 3, 2, 1:
           Prompt for password input.
           Store the password in the stack.
           Check if the password is correct
                 if correct, print "Password correct! Access granted." and break the loop.
                 If incorrect, decrement attemptsLeft and print "Incorrect password." or "No more attempts left."

3-Print Attempt History
        After loop finishes, print all the stored password attempts.

4-Memory Cleanup:
        Free memory allocated for each password attempt in the stack.        
                 

           
       
