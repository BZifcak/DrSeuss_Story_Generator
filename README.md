**Dr Seuss style Word predictor**
This program uses a hashmap to hash a Dr Seuss story (could be replaced with any text), and the reproduces text in the "voice" of the author. 
Each word in the text is a key for the hash, and the value array is all the words that appear after it.
The new text is made using random number generation to determine the next word from the value array of occurences. So the more a word appears in the value array, the more likely it will be produced.
