import random as ran

words = []  #take multiple inputs
no = int(input("Player 1, number of words you want to add to add to list: "))
for i in range(no):
    words.append(str(input("Enter the sentence(s): ")))


x = ran.randint(0, len(words)-1)  #select a random input
temp = words[x] #assign the word to another variable
temp1 = ''  #initialize string to remove letters from the word, also to avoid errors because of temp


def randomize(temp):

    global temp1
    y = ran.randint(len(words[x])-1, len(words[x])) #randomize number of letters to be removed
    for i in range(y):
        z = ran.randint(0, len(words[x])-1) #select random position to remove letter
        temp = temp.replace(temp[z], "_")
    temp1 = temp1 + temp
    print("\n\n\n\n\n\n", temp1)


def p2():
    print('''Following is the hangman diagram:
              ---+
    	      |  |
    	     _0_ |
    	      |	 |
    	     / \ |
    		    _|_
You have 9 chances to guess the word correctly.''')


counter = 9 #initialize count for the number of chances player 2 has


def check(counter): #display messages if player 2 gives wrong input
    if counter == 9:
        print('''Current:





                    __''')
    elif counter == 8:
        print('''Current:




                     |
                    _|_''')
    elif counter == 7:
        print('''Current:


                     |
                     |
                     |
                    _|_''')
    elif counter == 6:
        print('''Current:
                     +
                     |
                     |
                     |
                     |
                    _|_''')
    elif counter == 5:
        print('''Current:
                   --+
                     |
                     |
                     |
                     |
                    _|_''')
    elif counter == 4:
        print('''Current:
                   --+
                     |
                     |
                     |
                / \  |
                    _|_''')
    elif counter == 3:
        print('''Current:
                   --+
        	         |
        	     _   |
        	      |	 |
        	     / \ |
        		    _|_''')
    elif counter == 2:
        print('''Current:
                  ---+
        	         |
        	     _ _ |
        	      |	 |
        	     / \ |
        		    _|_''')
    elif counter == 1:
        print('''Current:
                  ---+
        	      |  |
        	     _0_ |
        	      |	 |
        	     / \ |
        		    _|_
        		Game Over, Player 1 won the game!''')

pos=[] #initialize list to find all the positions of a letter given by player 2

def find_all(s, c): #find all the positions
    idx = s.find(c)
    while idx != -1:
        pos.append(idx)
        idx = s.find(c, idx + 1)


def main(counter, temp1):

    while counter > 0:
        choice = input("Player 2, please enter a letter: ") #check if letter is in word
        if choice in words[x]:
            find_all(words[x], choice)
            for i in range(len(pos)):   #display word by adding the correct letter in all the correct positions
                temp1 = list(temp1)
                temp1[pos[i]] = choice
                temp1 = ''.join(temp1)
            pos.clear() #clear the list for the next loop

        else:
            check(counter)
            counter = counter-1
        print(temp1)
        if temp1 == words[x]:
            print("Game over, Player 2 has won the game!")
            counter = 0


randomize(temp)
p2()
main(counter, temp1)