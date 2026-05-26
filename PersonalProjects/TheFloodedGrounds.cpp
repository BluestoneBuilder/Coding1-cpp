//A text adventure horror game I decided to make
//Mac: g++ TheFloodedGrounds.cpp -o TheFloodedGrounds && ./TheFloodedGrounds
//Windows: cl /EHsc TheFloodedGrounds.cpp && TheFloodedGrounds

#include <iostream>
#include <string>
using namespace std;

string displayNextStanza(string text, string inputPrompt = "Press Enter to continue")
{
    string input;
    cout << "\n" << text << "\n";
    cout << "(" << inputPrompt << ")\n";
    getline(cin, input);
    return input;
}
string displayInteractiveStanza(string text, string inputPrompt)
{
    string input;
    cout << "\n" << text << "\n";
    cout << "(" << inputPrompt << ")\n";
    getline(cin, input);
    while (true) 
    {
        if(input == "")
        {
            cout << "(" << inputPrompt << ")\n";
            getline(cin, input);
        }
        else
        {
            break;
        }
    }
    return input;
}
int main()
{
    string player;
    string input;
    //Player greeting
    player = displayInteractiveStanza("Welcome Player!\nWhat is your name?", "Enter your name");
    input = displayNextStanza("Greetings, " + player + ". Let's set the stage, shall we?");
    
    //Intro
    input = displayNextStanza("You moved into a small rural town in Washington due to a job opening. You landed a job at an electrical plant called 'Brenden's Utilities & Zone of Services' or 'BuzServices' for short (a real comedian). You took the night shift as the only maintenance worker willing to take those hours. You really don't mind the hours, or the solitude, but your boss gave you one main rule to adhere to while you work: Don't let the water in.");
    if(displayInteractiveStanza("The town had a reputation for a large amount of rainfall and frequent flooding, which was a no go for anything to do with electricity. This meant that if there was ever any rain or sign of flooding, all doors had to be locked shut, and the ceiling had to be watched for leaks, or weakspots. Furthermore, if the moisture in the facility reached a certain threshold, then the facility cut power to avoid catastrophe, but as the main power supplier for the entire town, this had to be avoided at all costs. While the strict guidelines seemed daunting, the work itself seemed easy enough, simply consisting of basic maintenance and repair of systems. Are you ready for your first day?", "yes, no") == "yes")
    {
        cout << "\nGreat!\n";
    }
    else 
    {
        cout << "\nThat's too bad. You show up anyways.\n";
    }
    displayNextStanza("----Day 1----");
    //first shift
    input = displayNextStanza("You approach the building. The sky is cloudy but you're not expecting rain today. You enter through the metal door in the front, which scrapes across the concrete ground as it opens. You leave the door unlocked and proceed into the building. You walk through a long, dimly lit corridor lined with wiring and pipes as you make your way to the employee locker room. You enter the locker room, which is somehow even more dimly lit than the hallway. The ceiling hangs low and the room smells unpleasant, a droning electrical hum being the only sound to fill the silence.");
    string passcode = displayInteractiveStanza("You find the locker assigned to you, locker #13, and you attempt to unlock it.", "Enter your passcode");
    input = displayInteractiveStanza("You enter " + passcode + " into the dial of the locker, and it squeaks open. Inside is your uniform, with '" + player + "' written on a piece of tape placed on the nametag. You also find a box of tools, and a durable looking case at the bottom. What do you do?", "uniform, tools, case, leave");
    bool wearingUniform = false;
    bool hasTools = false;
    bool checkedCase = false;
    while(true)
    {
        if(checkedCase)
        {
            if(input == "case")
            {
                cout << "\nYou decide to leave that closed for now.\n";
            }
        }
        else 
        {
            if(input == "case")
            {
                cout << "\nYou pick up the case. It is pretty weighty and something metal jangles around inside as you pick it up. You undo the firm latches and open the lid. Inside you find a small firearm with spare ammo. You are caught off guard and wonder why such a thing would be in your locker. Perhaps they have dealt with intruders before. You close the case promptly and put it back in the bottom of your locker, not wanting to mess with it any further.\n";
                checkedCase = true;
            }
        }
        if(wearingUniform)
        {
            if(input == "uniform")
                cout << "\nLooking sharp!\n";
        }
        else 
        {
            if(input == "uniform")
            {
                cout << "\nYou put on the uniform which makes you feel a little less out of place. It's a bit too big. It must be from the guy who worked here before you. Oh, well. You probably wear it better than he did anyway.\n";
                wearingUniform = true;
            }
        }
        if(hasTools)
        {
            if(input == "leave")
            {
                if(!wearingUniform)
                {
                    cout << "\nYou decide not to put on your uniform and leave the locker room naked. Interesting choice. ";
                }
                input = displayNextStanza("Fully equipped, you head down the hall to the central corridor of the building. Faint buzzing and the groan of settling metal echoes throughout.");
                break;
            }
            else if(input == "tools")
            {
                cout << "\nIt's not much but it'll do.\n";
            }
        }
        else
        {
            if(input == "leave")
            {
                cout << "\nYou at least need your tools before you proceed to your work.\n";
            }
            else if(input == "tools")
            {
                cout << "\nYou pick up the toolkit and open it. The tools inside are rusted, dirty, and well-worn. You shrug, having worked with worse before. You hook the kit onto your belt buckle, ready to leave and get started on your work.\n";
                hasTools = true;
            }
        }
        cout << "(uniform, tools, case, leave)\n";
        getline(cin, input);
    }
    bool moistureChecked = false;
    bool fusesReplaced = false;
    bool generatorFueled = false;
    input = displayInteractiveStanza("Directly to your right is the moisture guage for the building. Down the hallway to your left is the fuse box room, and straight ahead is the generator room. Where will you go?", "moisture, fuse, generator, clock out");
    while(true)
    {
        if(input == "moisture")
        {
            input = displayNextStanza("The moisture level is currently reading at 30 percent humidity, which is well within the green zone.");
            moistureChecked = true;
        }
        else if(input == "fuse")
        {
            input = displayInteractiveStanza("You walk into the fuse room. There are shelves lined with boxes of spare fuses. There is a large cabinet against the back wall labled 'moisture pervention' which is completely empty, lovely. In front of you is the secondary fuse box, which has a number of wires extending out of it in various directions.", "check fuse, leave");
            while(true)
            {
                if(input == "check fuse")
                {
                    if(fusesReplaced)
                    {
                        input = displayInteractiveStanza("You pull open the secondary fuse box. It is a bit corroded but the new fuse you put in is nice and shiny. Good job, " + player + "!", "check fuse, replace fuse, leave");
                    }
                    else
                    {
                        input = displayInteractiveStanza("You pull open the secondary fuse box. It is a bit corroded and the fuse inside looks a bit worse for wear. Probably a good idea to replace it.", "check fuse, replace fuse, leave");
                    }
                }
                else if(input == "replace fuse")
                {
                    if(fusesReplaced)
                    {
                        input = displayInteractiveStanza("You already put a shiny new fuse on there. No need to replace it again today.", "check fuse, replace fuse, leave");
                    }
                    else
                    {
                        input = displayInteractiveStanza("You grab the old fuse and pull it out. The box zaps your hand as you pull it out. Maybe wear gloves next time. You grab a shiny new fuse out of a box in the room and place it into the fuse box. The light above it comes. Well done.", "check fuse, replace fuse, leave");
                        fusesReplaced = true;
                    }
                }
                else if(input == "leave")
                {
                    break;
                }
                else 
                {
                    cout << "\n(check fuse, replace fuse, leave)\n";
                    getline(cin, input);
                }
            }
            displayNextStanza("You head back out to the main corridor.");
        }
        else if(input == "generator")
        {
            input = displayInteractiveStanza("You enter the generator room. The hum in here is loud and the smell of gas permeates the air. You look and find the emergency backup generator which shows signs of wear from frequent use. You question how much this thing could be getting used around here.", "check generator, leave");
            while(true)
            {
                if(input == "check generator")
                {
                    if(generatorFueled)
                    {
                        input = displayInteractiveStanza("The generator is now fully fueled in case you need it.", "check generator, refuel generator, leave");
                    }
                    else
                    {
                        input = displayInteractiveStanza("The starter cable on the generator has been snapped and retied, likely from excessive pulling. You look at the guage on the side and see that the fuel level of the generator is in the yellow, meaning it could definitely use some fuel.", "check generator, refuel generator, leave");
                    }
                }
                else if(input == "refuel generator")
                {
                    if(generatorFueled)
                    {
                        input = displayInteractiveStanza("You decide to add more fuel even though it is already filled all the way. Some of it splashes on the ground. You stare at the puddle you made. Not the brightest, are you?", "check generator, refuel generator, leave");
                    }
                    else
                    {
                        input = displayInteractiveStanza("You unscrew the cap and fill up the fuel to the top. The guage takes its time catching up and eventually reads as fully fueled. Well done.", "check generator, refuel generator, leave");
                        generatorFueled = true;
                    }
                }
                else if(input == "leave")
                {
                    break;
                }
                else 
                {
                    cout << "\n(check generator, refuel generator, leave)\n";
                    getline(cin, input);
                }
            }
            displayNextStanza("You head back out to the main corridor.");
        }
        else if(input == "clock out")
        {
            if(moistureChecked && fusesReplaced && generatorFueled)
            {
                break;
            }
            else 
            {
                displayNextStanza("You consider leaving, but there is still work to be done, and that wouldn't exactly be a good look for your first day.");
            }
        }
        cout << "\n(moisture, fuse, generator, clock out)\n";
        getline(cin, input);
    }
    displayNextStanza("You head out of the building, locking the door behind you after a job well done. You see storm clouds rolling in overhead as you head back home. You go to sleep for the night, ready for your next shift.");

    //Day 2
    displayNextStanza("----Day 2----", "Press Enter to wake up");

    displayNextStanza("You awake the next day without the sunlight you're used to. Rain taps on your window which feels tinted with the overcast darkness. You hoist yourself out of bed and head out the door. Rain comes down on your head as you get to your car. You wish you had an umbrella. You drive down the narrow road with your window wipers barely creating enough visibility. The town around you is earily quiet. Not another car is seen on the road for your entire trip, as if the rain had killed the town or simply sent it into hiding.");
    displayNextStanza("As you pull into the parking lot, you look for the setting sun that usually settles behind the building, but it isn't visible today behind the wall of cloud. You go to the front door, soaked in rain, and turn the handle. It creaks open without the need to unlock it. The shift before you must've forgotten to lock it. You head inside with an uneasy feeling.");

    //restart last shift loop
    input = displayInteractiveStanza("You shut the door behind you and lock it, remembering the procedure for a rainy day. As you walk down the main hallway, you see a series of moist footprints on the ground that all head towards the exit and the air is noticeably muggy. You make your way to the locker room. When you get inside, you find that the room is a mess. Supplies are strewn across the floor, lockers are left open, and some are even tipped over. The lights flicker and barely light the room. 'Last shift must've been drinking something strong' you tell yourself, but you can't shake the eerie feeling you're getting. You shrug it off and go to open your locker", "Enter your passcode");
    while(true)
    {
        if(input == passcode)
        {
            break;
        }
        else
        {
            input = displayInteractiveStanza("It doesn't budge. Try again.", "Enter your passcode");
        }
    }
    input = displayInteractiveStanza("The door squeaks open once again, but this time you can really feel the echo. You look inside your locker, which is the only organized one in the room, and start to prepare for work.", "uniform, tools, case, tidy up, leave");
    bool hasTidiedUp = false;
    wearingUniform = false;
    hasTools = false;
    checkedCase = false;
    while(true)
    {
        if(input == "uniform")
        {
            if(wearingUniform)
            {
                cout << "\nLooking sharp, " + player + "!\n";
            }
            else
            {
                cout << "\nYou put on your uniform. The tape on your name tag is starting to peal, revealing part of the name of whoever wore it before you, but the letters look intentionally scratched out. You press the tape back down.\n";
                wearingUniform = true;
            }
        }
        else if(input == "tools")
        {
            if(hasTools)
            {
                cout << "\nIt's not much but it'll do.\n";
            }
            else
            {
                cout << "\nYou look inside your toolkit and everything appears to be just as rusty as the day before, but your screwdriver appears to be covered in oil. Strange. Somebody on the day shift must've borrowed your tools.\n";
                hasTools = true;
            }
        }
        else if(input == "case")
        {
            if(checkedCase)
            {
                cout << "\nGood riddance. You don't want to worry about that thing anymore.\n";
            }
            else
            {
                cout << "\nYou hesitantly pick up the case, which looks to have been opened since yesterday, as one of the latches is now broken. You open it to find only the slot for a gun, and nothing inside except a clip with a single bullet. You ease up a little, feeling slightly relieved that there is no longer a gun in your work locker.\n";
                checkedCase = true;
            }
        }
        else if(input == "tidy up")
        {
            if(hasTidiedUp)
            {
                cout << "\nLooks good, but doesn't shake that uneasy feeling from you.\n";
            }
            else
            {
                cout << "\nYou decide to take a moment to straighten up the locker room. You tip the fallen lockers back upright and attempt to sort the supplies back into the lockers based on the name tags, but many of the supplies are missing. Why would the other workers have taken their tools home with them? That's gotta be some violation of policy or something like that. You step back and admire your handywork for a moment. You are proud of yourself. Well done, " << player << "!\n";
                hasTidiedUp = true;
            }
        }
        else if(input == "leave")
        {
            if(hasTools)
            {
                displayNextStanza("You ready yourself and proceed to the main corridor. A strange sound similar to the metal creaking echoes in the direction you're going.");
                break;
            }
            else
            {
                cout << "\nYou at least need your tools before you proceed to your work.\n";
            }
        }
        cout << "\n(uniform, tools, case, tidy up, leave)\n";
        getline(cin, input);
    }

    moistureChecked = false;
    fusesReplaced = false;
    generatorFueled = false;
    input = displayInteractiveStanza("Directly to your right is the moisture guage for the building. Down the hallway to your left is the fuse box room, and straight ahead is the generator room. Where will you go?", "moisture, fuse, generator, clock out");
    while(true)
    {
        if(input == "moisture")
        {
            if(moistureChecked)
            {
                displayNextStanza("The moisture level is steadily but slowly decreasing. That's relieving at least.");
            }
            else
            {
                input = displayNextStanza("The moisture level is currently reading at 65 percent humidity, which is much higher than normal. You make sure the dehumidifier is active and hope it's enough to keep the moisture from triggering a shutdown.");
                moistureChecked = true;
            }
        }
        else if(input == "fuse")
        {
            input = displayInteractiveStanza("You walk into the fuse room. The lights seem to have gone out in the room. Some of the boxes of fuses are strewn across the floor. The latch on the 'moisture pervention' cabinet has been broken off and the door hangs ajar. In front of you is the secondary fuse box, which has a number of wires extending out of it in various directions.", "cabinet, check fuse, leave");
            while(true)
            {
                if(input == "cabinet")
                {
                    if(fusesReplaced)
                    {
                        input = displayInteractiveStanza("With the light back on, you can see the the interior of the cabinet is soaked in blood. It gives you chills so you leave it closed.", "cabinet, check fuse, replace fuse, leave");
                    }
                    else
                    {
                        input = displayInteractiveStanza("You open the 'moisture prevention' cabinet to find that most of the supplies are gone. It's a bit too dark to see but it looks like the inside of the cabinet is convered in spilled oil, just like your tools. You find an old book on the inside. Looks to be written by a local author. The book is titled 'They Come When It Rains'. You can't make out the words on any of the pages since the book is also soaked.", "cabinet, check fuse, replace fuse, leave");
                    }
                }
                else if(input == "check fuse")
                {
                    if(fusesReplaced)
                    {
                        input = displayInteractiveStanza("You pull open the secondary fuse box. The scorch marks on the box heavily contrast the new fuse you put inside. Good job, " + player + "!", "cabinet, check fuse, replace fuse, leave");
                    }
                    else
                    {
                        input = displayInteractiveStanza("You pull open the secondary fuse box. The brand new fuse you added yesterday is completely blown out. Strange. Definitely needs replaced.", "cabinet, check fuse, replace fuse, leave");
                    }
                }
                else if(input == "replace fuse")
                {
                    if(fusesReplaced)
                    {
                        input = displayInteractiveStanza("You already put a shiny new fuse on there. No need to replace it again today. You hope this one lasts a little longer.", "cabiinet, check fuse, replace fuse, leave");
                    }
                    else
                    {
                        input = displayInteractiveStanza("You pull out the scortched and blown fuse, replacing it with a new one. The light comes on above the box, then shortly after, the light in the room comes on. Your satisfaction is short lived though, as the light reveals that the 'oil' on your screwdriver is actually blood. Your eyes widen with a haunted expression. You only hope that someone mistakenly cut themself with the screwdriver but you know you're likely wrong. You try to keep your mind off these things.", "cabinet, check fuse, replace fuse, leave");
                        fusesReplaced = true;
                    }
                }
                else if(input == "leave")
                {
                    break;
                }
                else 
                {
                    cout << "\n(cabinet, check fuse, replace fuse, leave)\n";
                    getline(cin, input);
                }
            }
            displayNextStanza("You head back out to the main corridor.");
        }
        else if(input == "generator")
        {
            input = displayInteractiveStanza("You enter the generator room, which is just as disheveled as the others. The hum in here is loud and the smell of gas and something metalic permeates the air. You see the backup generator which seems to have been used since the previous day. You're moderately concerned.", "check generator, leave");
            while(true)
            {
                if(input == "check generator")
                {
                    if(generatorFueled)
                    {
                        input = displayInteractiveStanza("You're glad you fueled it, but the misplaced fire arm makes you uneasy.", "check generator, refuel generator, leave");
                    }
                    else
                    {
                        input = displayInteractiveStanza("As you inspect the generator, you find that the power switch is still on, but the fuel is competely drained. It must've been completely expended. Strange. You flip the switch off, but it definitely needs fuel.", "check generator, refuel generator, leave");
                    }
                }
                else if(input == "refuel generator")
                {
                    if(generatorFueled)
                    {
                        input = displayInteractiveStanza("You decide to add more fuel even though it is already filled all the way. Some of it splashes on the ground. You stare at the puddle you made. Your mind is too stressed to think right now.", "check generator, refuel generator, leave");
                    }
                    else
                    {
                        input = displayInteractiveStanza("You grab a gas can and fill the generator all the way up. You use the entire thing since the generator needed filled all the way. As you go to sit the empty can down, it clangs against something metalic. You look to see a discarded pistol, like the kind missing from your case. The slide is pulled back and there are empty shells on the ground next to it. Was somebody shooting something? Or someone? You take a step back from the generator, not quite sure what to do.", "check generator, refuel generator, leave");
                        generatorFueled = true;
                    }
                }
                else if(input == "leave")
                {
                    break;
                }
                else 
                {
                    cout << "\n(check generator, refuel generator, leave)\n";
                    getline(cin, input);
                }
            }
            displayNextStanza("You promptly get out of the room and head back out to the main corridor.");
        }
        else if(input == "clock out")
        {
            if(moistureChecked && fusesReplaced && generatorFueled)
            {
                displayNextStanza("You quickly head towards the door, not even remembering to take off your uniform since everything has you on edge. Your foot prints begin to follow the others you found a moment ago. As you get closer to the door, you hear your shoes begin to lightly splash against the ground, as a puddle has formed around the door. Why does it have to be raining today?");
                break;
            }
            else 
            {
                displayNextStanza("You feel like leaving is the smart thing to do, but you decide to stay just long enough to finish up your tasks because you like money.");
            }
        }
        cout << "\n(moisture, fuse, generator, clock out)\n";
        getline(cin, input);
    }
    
    displayNextStanza("You turn the handle and push on the exit door, but it doesn't seem to move. You lean against the door to force it open.");
    for(int i = 0; i < 3; i++)
    {
        displayNextStanza("Pushing...", "Press Enter to push");
    }
    displayNextStanza("As the door finally come open a tad, water begins to rush into the building at your feet. You quickly slam the door shut again. It must be flooded pretty high out there. You turn around to head back into the facility to pass the time until the flooding dies down");
    displayNextStanza("As you make your way back to the locker room, you notice that a layer of water has formed on the floor and the ceiling has begun to drip in multiple places. As you begin to take your uniform off, you start to hear strange noises off in some distant part of the building. You question whether or not it's the creaking of the building itself, but the groaning noises sound sort of organic. Just then, the lights go out and the building quiets to an eerie stillness.");
    displayNextStanza("With all other background noise cut out, you can clearly hear that somebody or something else is in the facility. You hear the quiet splashing of feet in the distance and groaning that sounds like another person making it, but something is slightly off about the tone, like it's a little too airy, as if whatever is making the noise is expending its final breaths. You hesitantly grab a flash light and move slowly to investigate.", "Press Enter to move forward");
    displayNextStanza("You reach the main corridor, and the groaning is slowly getting louder. As it gets clearer it begins to sound less and less like any normal person could make it. You hear that the source of it is in your boss's office, down the front hallway, past the generator room.", "Press Enter to move forward");
    displayNextStanza("You reach the door of the boss's office, and it's clear something is distressed or hurt inside. You grab your screw driver tightly in your hand and prepare to open the door.", "Press Enter to open");
    displayNextStanza("||\n||=\n||", "Press Enter to open");
    displayNextStanza("| |\n| |=\n| |", "Press Enter to open");
    displayNextStanza("|  |\n|  |=\n|  |", "Press Enter to open");
    displayNextStanza("|   |\n|   |=\n|   |", "Press Enter to open");
    displayNextStanza("As you look inside the office, you see someone, or something, huddled against the wall in a fetal position. It looks to be injured or bleeding, creating a diluted puddle around its body. You hear it groan in a way no man could replicate. Your entry seems to have startled it.");
    displayNextStanza("It turns slowly back towards you. It stands hunched and looms over the top of everything else in the room. It looks you in the eyes and you get a good look at its face, or what you think is a face. It looks more like the skull of an animal, decayed and blood soaked. Two clouded eyes pierce into you with their gaze. Its tall body is lanky and sunken in, as if malnourished. You look at its torso where blood drips from four or five clean holes that look to be bullet wounds. You feel frozen in fear as it begins to approach.", "PRESS ENTER TO RUN");
    displayNextStanza("You try to move but can't seem to make your body respond. It gets closer until it looms directly over you, staring you down with a predatorial gaze.", "PRESS ENTER TO RUN");
    while(true)
    {
        displayNextStanza("With a jolt you feel your body respond again. You turn and make a break for it down the hallway. You tredge as quickly as you can through the rising water level. You look back and the creature is following a ways behind, slowly walking throught the high water as if it isn't there at all, its eyes never leaving yours.");
        bool hasGun = false;
        bool hasBullets = false;
        bool ending = false;
        
        input = displayInteractiveStanza("You reach the main corridor. The creature gets closer. Where do you go?", "locker room, fuse room, generator room, front door");
        while(true)
        {
            if(input == "locker room")
            {
                input = displayInteractiveStanza("You rush to the locker room as quickly as you can. What do you do?", "hide, your locker, leave");
                while (true)
                {
                    if(input == "hide")
                    {
                        displayNextStanza("You quickly pull open a nearby locker, stuffing yourself inside and closing the door. The creature enters the room shortly after.");
                        displayNextStanza("The creature slowly stalks through the room. It walks slowly past the locker you're in. Suddenly it stops, sniffs the air, and turns slowly to look directly in the slats of the locker, right at you.");
                        if(hasGun)
                        {
                            if(hasBullets)
                            {
                                displayNextStanza("You ready your gun and prime it to fire. Just then, the beast tears the locker door off its hinges. You fire at it with your only bullet, but you only manage to land a body shot with it moving so much. It quickly slashes through your abdomen as its movements slow from the injury. You bleed out in that locker, hoping the shot was enough to eventually kill this thing and spare the rest of the town, and the world.");
                            }
                            else
                            {
                                displayNextStanza("You ready your gun and prime it to fire. Just then, the beast tears the locker door off its hinges. You point your gun at it and pull the trigger, but you hear only a tick. Your clip is empty. You are quickly devoured and forgotten about in that facility, likely not to be found for a long time, and your efforts never known.");
                            }
                        }
                        else 
                        {
                            displayNextStanza("You hold your breath and hope it moves on. Just then, the beast tears the locker door off its hinges. You are quickly devoured and forgotten about in that facility, likely not to be found for a long time, known only as another coward who let the water in.");
                        }
                        ending = true;
                        break;
                    }
                    else if(input == "your locker")
                    {
                        input = displayInteractiveStanza("You go to open your locker, hoping to find something useful inside.", "Enter your passcode");
                        while(true)
                        {
                            if(input == passcode)
                            {
                                break;
                            }
                            else
                            {
                                input = displayInteractiveStanza("It doesn't budge. Try again.", "Enter your passcode");
                            }
                        }
                        cout << "\nYou pull open your locker, finding a gun case at the bottom. You pull it open and find a pistol clip with a single bullet inside. You grab it and shut your locker.\n";
                        hasBullets = true;
                    }
                    else if (input == "leave")
                    {
                        displayNextStanza("You rush back to the main corridor.");
                        break;
                    }
                    cout << "\n(hide, your locker, leave)\n";
                    getline(cin, input);
                }
            }
            else if(input == "fuse room")
            {
                input = displayInteractiveStanza("You rush to the locker room as quickly as you can. What do you do?", "hide, leave");
                while(true)
                {
                    if(input == "hide")
                    {
                        displayNextStanza("You rush to the cabinet and stuff yourself inside, closing the door. It smells strongly of blood in here. The creature enters shortly after.");
                        displayNextStanza("The creature slowly stalks through the room. It walks slowly past the cabinet you're in. Suddenly it stops, sniffs the air, but it can't seem to get a lock on your scent.");
                        if(hasGun)
                        {
                            displayNextStanza("You aim your gun throught the small gap in the cabinet door. You wait for the beast to settle into a stillness and train your sights directly at its skull. You pull the trigger.");
                            if(hasBullets)
                            {
                                displayNextStanza("The bang echoes through the building as the creature slumps to the ground. You slowly emerge from the locker, making sure the thing is dead. You run out of there to the front door, flinging it open. The flood waters rush in but you escape. You spend the next hour pushing your car out of the waters and up onto the raised highway. You manage to get the drowned engine to start. You get in and start driving. You don't know where to just yet, but somewhere without rain. You leave the dead town behind. You may not sleep again for a long time, but at least there's one less monster running around.");
                                displayNextStanza("Over the course of the next week, the entire town is destroyed and swept away by the flood waters, the only remaining artifact being a signed copy of 'They Come When It Rains' that you kept from the facility with not a single one of the pages being legible, but that doesn't matter to you because you already know the story.");
                            }
                            else
                            {
                                displayNextStanza("A click echoes through the room because there was no ammo for the gun to fire. The beast halts and slowly turns to look directly at you.");
                                displayNextStanza("You hold your breath and hope it moves on. Just then, the beast tears the cabinet door off its hinges. You are quickly devoured and forgotten about in that facility, likely not to be found for a long time, known only as another coward who let the water in.");
                            }
                        }
                        else
                        {
                            displayNextStanza("You stay hidden in that cabinet for hours. Eventually, the beast lays in the shallow water and begins to sleep. You use the opportunuty to sneak past it, out of the room. You make your way to the front door and slowly push it open.");
                            displayNextStanza("You open it slowly enough that the water equalizes in and out of the facility. You make a break for it, wading through the flood waters and coming to a raised highway. You run down the highway as far as your legs will take you, leaving the town to deal with its own demons.");
                        }
                        ending = true;
                        break;
                    }
                    else if(input == "leave")
                    {
                        displayNextStanza("You rush back to the main corridor.");
                        break;
                    }
                    cout << "\n(hide, leave)\n";
                    getline(cin, input);
                }
            }
            else if(input == "generator room")
            {
                input = displayInteractiveStanza("You rush to the generator room as quickly as you can. What do you do?", "check generator, leave");
                while (true)
                {
                    if(input == "check generator")
                    {
                        if(hasGun)
                        {
                            cout << "\nNow there's nothing left here, so you're just staring at a generator while the creature is on its way.\n";
                        }
                        else
                        {
                            cout << "\nYou look over by the generator and see a gun next to it. You grab it";
                            if(hasBullets)
                            {
                                cout << " and load the bullet you found into it.\n";
                            }
                            else
                            {
                                cout << ", but there are no bullets inside.\n";
                            }
                            hasGun = true;
                        }
                    }
                    else if(input == "leave")
                    {
                        displayNextStanza("You rush back to the main corridor.");
                        break;
                    }
                    cout << "\n(check generator, leave)\n";
                    getline(cin, input);
                }
            }
            else if(input == "front door")
            {
                displayNextStanza("You decide to make a break for it and rush to the front door. You grab the door handle and pull it open. Water rushes in through the opening, pushing you back as the beast charges for you.");
                if(hasGun)
                {
                    displayNextStanza("You aim your gun at the beast as the water sweeps you towards it, but it swipes your gun away and quickly devours you. You are forgotten about in that facility, likely not to be found for a long time, known only as another coward who let the water in.");
                }
                else
                {
                    displayNextStanza("The water sweeps you right into the grasp of the beast. You are quickly devoured and forgotten about in that facility, likely not to be found for a long time, known only as another coward who let the water in.");
                }
                ending = true;
            }
            else 
            {
                displayNextStanza("Unable to properly decide, you stand there frozen in fear.");
            }
            if(ending)
                break;
            cout << "\nThe creature gets closer.\n(locker room, fuse room, generator room, front door)\n";
            getline(cin, input);
        }
        bool startAgain = false;
        while(true)
        {
            input = displayInteractiveStanza("Would you like to play this section again?", "yes, no");
            if(input == "yes")
            {
                startAgain = true;
                break;
            }
            else if(input == "no")
            {
                break;
            }
        }
        if(startAgain)
        {
            displayNextStanza("You suddenly snap back to consciousness and you're back at the door of the office, staring down the creature. Must've been daydreaming.","PRESS ENTER TO RUN");
        }
        else
        {
            cout << "\nThanks for playing! And don't let the water in." << endl;
            break;
        }
    }

    return 0;
}