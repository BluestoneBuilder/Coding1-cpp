//A text adventure horror game I decided to make
//g++ TheFloodedGrounds.cpp -o TheFloodedGrounds && ./TheFloodedGrounds

#include <iostream>
#include <ctime>
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
    srand(time(0));
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
    bool fuzesReplaced = false;
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
                    if(fuzesReplaced)
                    {
                        input = displayInteractiveStanza("You pull open the secondary fuse box. It is a bit corroded but the new fuze you put in is nice and shiny. Good job, " + player + "!", "check fuse, replace fuse, leave");
                    }
                    else
                    {
                        input = displayInteractiveStanza("You pull open the secondary fuse box. It is a bit corroded and the fuse inside looks a bit worse for wear. Probably a good idea to replace it.", "check fuse, replace fuse, leave");
                    }
                }
                else if(input == "replace fuse")
                {
                    if(fuzesReplaced)
                    {
                        input = displayInteractiveStanza("You already put a shiny new fuse on there. No need to replace it again today.", "check fuse, replace fuse, leave");
                    }
                    else
                    {
                        input = displayInteractiveStanza("You grab the old fuse and pull it out. The box zaps your hand as you pull it out. Maybe wear gloves next time. You grab a shiny new fuse out of a box in the room and place it into the fuse box. The light above it comes. Well done.", "check fuse, replace fuse, leave");
                        fuzesReplaced = true;
                    }
                }
                else if(input == "leave")
                {
                    break;
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
            }
            displayNextStanza("You head back out to the main corridor.");
        }
        else if(input == "clock out")
        {
            if(moistureChecked && fuzesReplaced && generatorFueled)
            {
                //clock out text
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
                displayNextStanza("You ready yourself and proceed to the main corridor, still getting eerie vibes from the area around you.");
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

    return 0;
}