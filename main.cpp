#include <iostream>
#include "voice.h"
#include <time.h>
#include <stdlib.h>

using namespace std;
int main() {
    srand(time(NULL));
    int hashfn; // for which hash fn to use
    int collfn; // for which  collision fn to use
    /*************************************************/
    /* test 1
    /* For this:
     * 1) Create your hNode.cpp.  You'll need to write the hNode constructors and the addValue methods.
     *    For later tests, you'll have to write the getRandomValue method as well as the
     *    destructor (as defined in hNode.h)
     * 2) in HashMap.cpp, write the constructors for hashMap, the addKeyAndValue, the getIndex,
     *    insertNewKeyandValue, and dealWithCollisions (as defined in hashMap.cpp).
     * 3) once you have these working, you can test the following code and you should get exactly the
     *    output I've included below this main function (after it closes)
     */
    hashfn = 1; // for testing - uses my hash fn
    collfn = 1; // for testing - uses my collisionfn

    voice *k = new voice("ShortGEaH.txt","FirstTestOut.txt", hashfn, collfn);
    k->readFile();
    k->ht->printMap();
    /**********************************/
    /* Test2
    /* For this part you'll be writing the destructor for HNode and hashMap.  Once done, comment in
     * following line of code and you should get something similar to the output I've included
     * below main and test1 output (The only output you actually get is optional output I included in
     * the hNode destructor that printed out that I was destroying a key)
    */
    delete k;

    /*End of Test 2 */
    /***********************************/
    /* Test 3
     * This is challenging.  When a hashMap gets too full, there are too many collisions for it to
     * be efficient any more.  That magic fullness number is 70%.  So you want to write the method
     * ckIfNeedToRehash() (which is called in the insertNewKeyandValue method ).
     * the ckIfNeedToRehash method checks if the map is 70% full, and, if so, calls the reHash method
     * which is somewhat challenging and requires a good understanding of pointers so that you don't
     * lose the map, don't rehash into the wrong map, and don't use the wrong table size when you're
     * rehashing.  I've included more detailed instructions in hashMap.cpp.
     * When you have it working, uncomment out the following lines of code and test your rehash method.
     * Since you're still using my set in stone hash function and collision function, you should get
     * the exact output I've included below the main under Test 3
     * For the rehash method, you may wish to write the findKeyIndex method.  We'll be using
     * it later in the writeFile method, but it might come in useful in the reHash method as
     * well.
     * */
     k = new voice("MedGEaH.txt","SecondTestOut.txt", hashfn, collfn);
     k->readFile();
     k->ht->printMap();
     /* End of test 3*/
 /* Part 4:
  * from now on I can't give you definitive output because it depends on what hashing function you write and what
  * collision function you write.
  * I am giving you the steps for how I'd approach this
  * Write your first hashing function.
  * delete k;
  * Test your hashing function with:
  * hashfn = 2;
  * k = new voice("ShortGEaH.txt","FirstTestOut.txt", hashfn, collfn);
    k->readFile();
    k->ht->printMap();
  * If that works, try it with the larger data set:
  * delete k;
  * k = new voice("MedGEaH.txt","FirstTestOut.txt", hashfn, collfn);
    k->readFile();
    k->ht->printMap();

    If all of this works, write your second hashing function and repeat from delete k down to the print map,
    only set hashfn to 3;

    Once you have all this working, switch the hashfn to 1, and the collfn to 2, and then write your first
    collision function
    delete the old map (k)
    and read in the short text file  for testing. (steps are the same as above)

    Then test on the MedGEaH text file

    THen write your second collision function, switch collfn to 3, and test your second collision function
    on the ShortGEaH text file.

    Then on the MedGEaH text file.

    THen test the 4 permutations:
    hashfn = 2, collfn = 2; hashfn = 2, collfn = 3; hashfn = 3, collfn = 2; hashfn = 3, collfn = 3;

    When you've got all that working, add in a call to
    k->writeFile();

    And, once that's working:
    add the following code:
    k = new voice("DrSeuss.txt","SeussOut2_2.txt", 2, 2);
    k->readFile();
    k->writeFile();
    delete k;
    k = new voice("DrSeuss.txt","SeussOut3_2.txt", 3, 2);
    delete k;
    k = new voice("DrSeuss.txt","SeussOut2_3.txt", 2, 3);
    delete k;
    k = new voice("DrSeuss.txt","SeussOut3_3.txt", 3, 3);
  *
  *I'm including my SeussOut1_1.txt at the very bottom
  */
 delete k;
 k = new voice("DrSeuss.txt","SeussOut1_1.txt", 1, 1);
 k->readFile();
 k->writeFile();
    return 0;
}
/*******************************************************************************/
/* Test 1 output:
* In printMap(): Included for testing purposes!!! MapSize: 57, KeysCt: 35
car! (1): Sam!,
anywhere. (2): I,
be! (4): I,
train! (5): not,
you (7): on,
Let (8): me,
tree! (9): Not,
there. (12): I,
ham. (14): I,
I (16): will, will, will, will, do, do,
green (17): eggs,
them, (18): Sam-I-am.,
Not (20): on, in,
here (21): or,
and (22): ham.,
eggs (23): and,
house. (24): I,
like (25): them,,
Sam-I-am. (26):
eat (29): them, them, them, them, green,
mouse. (30): I,
them (31): in, with, here, anywhere.,
train? (35): Not,
Sam! (37): Let,
me (39): be!,
a (40): train?, train!, tree!, car!, house., mouse.,
will (41): not, not, not, not,
would (42): you,
do (43): not, not,
in (44): a, a, a,
with (45): a,
on (50): a, a,
you, (51): would,
not (52): in, eat, eat, eat, eat, eat, like,
or (54): there.,
*/
/* End of Test 1 */
/*******************************************************************************/
/* Test 2 output (of the destructors):
****************************************************************
Deleting car!
Deleting anywhere.
Deleting be!
Deleting train!
Deleting you
Deleting Let
Deleting tree!
Deleting there.
Deleting ham.
Deleting I
Deleting green
Deleting them,
Deleting Not
Deleting here
Deleting and
Deleting eggs
Deleting house.
Deleting like
Deleting Sam-I-am.
Deleting eat
Deleting mouse.
Deleting them
Deleting train?
Deleting Sam!
Deleting me
Deleting a
Deleting will
Deleting would
Deleting do
Deleting in
Deleting with
Deleting on
Deleting you,
Deleting not
Deleting or
Hash Map Destroyed
***************************************************************
*/
/* End of Test 2*/
/****************************************************************/
/* Test 3 output
 * In printMap(): Included for testing purposes!!! MapSize: 57, KeysCt: 35
car! (1): Sam!,
anywhere. (2): I,
be! (4): I,
train! (5): not,
you (7): on,
Let (8): me,
tree! (9): Not,
there. (12): I,
ham. (14): I,
I (16): will, will, will, will, do, do,
green (17): eggs,
them, (18): Sam-I-am.,
Not (20): on, in,
here (21): or,
and (22): ham.,
eggs (23): and,
house. (24): I,
like (25): them,,
Sam-I-am. (26):
eat (29): them, them, them, them, green,
mouse. (30): I,
them (31): in, with, here, anywhere.,
train? (35): Not,
Sam! (37): Let,
me (39): be!,
a (40): train?, train!, tree!, car!, house., mouse.,
will (41): not, not, not, not,
would (42): you,
do (43): not, not,
in (44): a, a, a,
with (45): a,
on (50): a, a,
you, (51): would,
not (52): in, eat, eat, eat, eat, eat, like,
or (54): there.,
***************************************************************
Deleting car!
Deleting anywhere.
Deleting be!
Deleting train!
Deleting you
Deleting Let
Deleting tree!
Deleting there.
Deleting ham.
Deleting I
Deleting green
Deleting them,
Deleting Not
Deleting here
Deleting and
Deleting eggs
Deleting house.
Deleting like
Deleting Sam-I-am.
Deleting eat
Deleting mouse.
Deleting them
Deleting train?
Deleting Sam!
Deleting me
Deleting a
Deleting will
Deleting would
Deleting do
Deleting in
Deleting with
Deleting on
Deleting you,
Deleting not
Deleting or
Hash Map Destroyed
***************************************************************
*****************************************************************
* REHASHING: 40/57
In printMap(): Included for testing purposes!!! MapSize: 57, KeysCt: 40
car! (1): You,
anywhere. (2): I,
them! (7): Eat,
tree! (9): I,
there. (12): I,
car. (14): You,
are. (16): I,
I (17): would, would, do, do, do, do, do, do, do,
be. (18): I,
green (19): eggs,
them. (20): Here, You,
see. (21): You,
could (22): not,, not,
like (23): them., them, them, them, them, them, them, them, green,
tree. (24): Not,
Not (25): in,
house. (26): I,
here (27): or,
eggs (28): and,
mouse. (29): I,
and (30): ham.,
them (31): in, in, with, in, with, here, anywhere.,
You (32): may, will, may, let,
box. (33): I,
fox. (37): I,
not, (39): could, in, could,
a (40): car., tree!, tree., car!, box., fox., house., mouse.,
will (41): see.,
would (42): not,, not,,
they (43): are.,
in (44): a, a, a, a, a, a,
may (45): like, like,
Here (46): they,
let (47): me,
me (48): be.,
do (49): not, not, not, not, not, not, not,
with (50): a, a,
not (52): in, like, like, like, like, like, like, like,
Eat (54): them.,
or (55): there.,
mapSize was: 57
mapSize is now: 127

In printMap(): Included for testing purposes!!! MapSize: 127, KeysCt: 59
not, (0): could, in, could, could, in, could, with,
Here (7): they, in,
you, (12): would, could, in,
Would (15): you,,
green (21): eggs, eggs,
anywhere. (24): I, I,
could (27): not,, not, not,, not,, you,,
Eat (28): them.,
here (39): or, or,
like (40): them., them, them, them, them, them, them, them, green, them,, them,,
eggs (41): and, and,
Let (42): me,
would (47): not,, not,, you, not,, not,,
them (49): in, in, with, in, with, here, anywhere., in, here, anywhere.,
Not (51): in, on, in,
and (53): ham., ham.,
In (56): the,
will (59): see., not, not, not,
eat (60): them, them, them, green,
they (61): are.,
You (63): may, will, may, let,
with (64): a, a, a,
train! (67): not,
Sam! (68): Let,
Sam-I-am. (69): Could, Say!,
the (70): dark?, dark!, dark?,
let (71): me,
dark! (72): Would,
I (73): would, would, do, do, do, do, do, do, do, do, would, would, will, will, will, do, do,
there. (74): I, I,
may (75): like, like,
Say! (80): In,
them! (82): Eat,
me (83): be., be!,
tree! (84): I, Not,
do (85): not, not, not, not, not, not, not, not, not, not,
house. (86): I, I,
not (87): in, like, like, like, like, like, like, like, like, in, eat, eat, eat, eat, like,
in (88): a, a, a, a, a, a, a, a, a, a, the, the,
car! (89): You, Sam!,
mouse. (91): I,
them, (93): Sam-I-am., Sam-I-am.,
on (94): a, a,
them. (95): Here, You,
you (96): on,
tree. (97): Not,
a (98): car., tree!, tree., car!, box., fox., house., mouse., train?, train!, tree!, car!, box., fox., house.,
or (99): there., there.,
train? (100): Not,
dark? (101): Here, ,
car. (102): You,
ham. (103): I, I,
are. (104): I,
be! (105): I,
see. (109): You,
be. (118): I,
box. (121): I, I,
Could (122): you,,
fox. (125): I, I,
*/
/* End of test 3 */
/**********************************************************************/
/* My output file.  Note that the number of hashing collisions and the
 * number of collisions are absolutely awful.  That's because my functions
 * just are awful.  Pretty much anything you write should give you better
 * numbers.  But.  Now you can see why the hash function adn the collision
 * function matter.
 * OUTPUT:
 ***********************************
 * Hash Function Collisions: 4968, Collision count: 4000427
I can’t say. should not like the next minute I just waiting. NO!
That's hard. I heard a quick Santy Claus hissed, And feed it
blows and we had to the high And plums! And he got
into a car. Not with my net. it came swimming by this
glorious place. And he made a house? Would stand on the coo
of a hole in the air and i bet, with me, friends.
Do I see!" Then I would buy that day they will make
you, could you, on a long, long must we saw was lifted
his head! he climbed up so good, so much softer than me!"
But, now, how much greater I'd chopped down with a ball. and
THEN! who was too slow. So he whiffed. He was something went
after another, they yelled at the whole room, and the Lorax and
puffed. "What's more," snapped the things i do if my hat! and
puzzling: "How could you, would not, Alone will top of a Great
Places! You're off four Truffula Fruits. "NOW... thanks to see enough. That's
the fake Santy Claus hissed, And a most likely reason of the
beaches. With banner flip-flapping, once stood just what to play. he got
lifted himself by the side of cold water. And the Whos, Staring
down at this game that cold, cold, cold, wet day.' now, here
or No more you'll escape from behind? Simple it's true that Sneetches
who had stars! They kept them in his Lerkim on the sleigh
And I'm being quite knows the chimney! Then he growled, with that
won't want to the hat. 'i always pick up in style, said
the things had stars every minute or not, on earth who had
to people just what SHOULD we are slow. So they hum, for
fun at Whoville! The trappings! Three thousand feet in a pot to
go down in no fear of a car! Sam! If which one
little toy man! and took the trees!" "I'm ruler", said the food
up with a train. Not in your head wasn't screwed on is
not like them away. then things fall! and slunk, with an unpleasant
bump. And they have to us apart. We're all the Grinch's small
pile of joy in this house! And, in the trees. I can.
He HADN'T stopped Christmas tree? WHY?" But, as fast as they should
you Lorax, "Now I'll stack 'em over with a sickening smack of
cold to rise Up over with my back And a great leaping
of Sneetches Were moping and you did!' said the king of pearls,
or waiting around here. oh, i bet, with Thing Two and footsy
as you succeed? Yes! You want 'bout two things in the tree
fall. i said the rain to get in bags. Then he grinned,
"are the fish in the best Sneetches forgot about it home to
the ones who has other Whos' mouses! It could not, could not,
upon thars! Then I need is the sun
*/