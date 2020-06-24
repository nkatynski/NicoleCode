def charDetector(sentence, searchLetter):
    count = letterInstances = 0
    while count < len(sentence):
        if(sentence[count].lower() == searchLetter.lower()):
            letterInstances += 1
        count += 1
    return letterInstances

sentence = "I am the very model of a modern major general."
searchLetter = 'e'

print("Starting sentence: " + sentence)
letterInstances = charDetector(sentence, searchLetter)
print(searchLetter + " is feathred " + str(letterInstances) + " times.")
