//By the Pixel Paladins: Eddie, Everett, and Alex
//Pallid Ground™ 2024

//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Prototypes
void mainMenu();
void displayUI();
void inventoryAdd(int slot);
void hp(int damage);
void DOT(int dpt, int turns, int which);
void stopRune(int runeNum);
void gameOver();
void battleUI();
void start();
void room1();
void room2();
void room3();
void finalRoom();
void credits();

//Global Variables
int choice;
int chance;
int ultChance;
int golemUlt = 1;
int golemDD = 0;
int necromancerUlt = 0;
int checkFireball = 0;
int health = 7;
int bosshp = 6;
int turn = 0;
int boss;
int dodge = 0;
int dmgPerTurn = 0;
int bossUlt = 0;
int bosscounter = 0;
int dptCount = 0;
int secondskip = 0;
int vitality = 3;
int avoidchance;
int DOTcount = 0;
int bossDOT = 0;

int inventory[10] = {};
char *inventorynames[10] = {"Fireball Rune", "Ice Rune", "Lightning Rune", "Vitality Rune"};

int main() //Main Function, goes to the starting area
{ 
  srand(time(NULL));
  mainMenu();
  return 0;
}

void mainMenu()//Displays Main Menu
{
  while (1)
    {
      choice = 0;

      system("clear");
      printf("Pallid Ground\n\n\n2024 by Pixel Paladins\n\n\n1. Play\n2. Exit\n\n>>> ");
      scanf("%d", &choice);
      if (choice == 1)
      {
        system("clear");
        start();
      }
      else if (choice == 2)
      {
        exit(0);
      }
      else
      {
        continue;
      }
    }
}

void displayUI() //Displays health and inventory and such
{
  int x;
  printf("Health: %d\n", health);
  printf("Inventory: ");
  printf("| ");
  for (x = 0; x < 10; x++)
  {
    if (inventory[x] != 0)
    {
      printf("%s | ", inventorynames[x]);
    }
  }
  printf("\n\n");
}

void battleUI() //Displays extra UI for the battle system
{
  system("clear");
  printf("Round %d\n", turn);
  if (turn % 2 == 0)
  {
    printf("Your turn.\n");
  }
  else
  {
    printf("Enemy's turn.\n");
  }
  printf("Boss HP: %d\n\n", bosshp);
}

void inventoryAdd(int slot) //Adds item to inventory
{
  inventory[slot] = 1;
}

void hp(int damage) //Subtracts health and checks for death
{
  health -= damage;
  if (health <= 0)
  {
    gameOver();
  }
}

void DOT(int dpt, int turns, int which) //Subtracts damage per turn
{
  if (turns == -1)
  {
    dmgPerTurn = 0;
    bossDOT = 0;
  }
  if (turns == 0 && which == 0)
  {
    health -= dmgPerTurn;
    if (health <= 0)
    {
      gameOver();
    }
    return;
  }
  else if (turns == 0 && which == 1)
  {
    bosshp -= bossDOT;
    return;
  }
  if (DOTcount < turns)
  {
    DOTcount++;
    if (which == 0)
    {
      dmgPerTurn += dpt;
      health -= dmgPerTurn;
      if (health <= 0)
      {
        gameOver();
      }
    }
    else
    {
      bossDOT += dpt;
      bosshp -= bossDOT;
    }
  }
}

void stopRune(int runeNum) //Blocks a rune's usage
{
  if (runeNum == 0)
  {
    inventory[0] = 0;
  }
  else if (runeNum == 1)
  {
    inventory[1] = 0;
  }
  else if (runeNum == 2) 
  {
    inventory[2] = 0;
  }
  else if (runeNum == 3)
  {
    inventory[3] = 0;
  }
}

void gameOver() //Game Over
{
  //system("clear");
  printf("\n\nGAME OVER\n\n\n");
  sleep(3);
  int i;
  for (i = 0; i < 4; i++) {
    inventory[i] = 0;
  }
  golemUlt = 1;
  golemDD = 0;
  necromancerUlt = 0;
  checkFireball = 0;
  health = 7;
  bosshp = 6;
  turn = 0;
  dodge = 0;
  dmgPerTurn = 0;
  bossUlt = 0;
  bosscounter = 0;
  dptCount = 0;
  secondskip = 0;
  vitality = 3;
  DOTcount = 0;
  bossDOT = 0;
  mainMenu();
}

void start() //Code for the starting Room
{
  while (1) //displays the options and allows the player to choose, displays narratives for each path
  {
    dmgPerTurn = 0;
    system("clear");
    displayUI();
    printf("You wake up and find yourself in a dark dungeon cell. The bars seem fairly battered and thin, and as you look out, you see a guard walking by. Sitting back down, you notice some item in the corner of the cell.\n\n1. Try and break the bars.\n2. Get the guard’s attention.\n3. Walk over to the corner.\n\n>>> ");
    scanf("%d", &choice);
    if (choice == 1)
    {
      while (1)
      {
        system("clear");
        displayUI();
        printf("You kick the bars of the door of the cell as hard as you can. To your surprise, the door swings open with a clatter. However, the guard notices and draws his sword.\n\n1. Engage in a fight with the guard!\n\n>>> ");
        scanf("%d", &choice);
        if (choice == 1)
        {
          hp(1);
          while(1)
          {
            system("clear");
            displayUI();
            printf("After throwing a couple punches, you realize you’re no match for his sword as the guard lands a hit. (-1 HP).\n\n1. Run away.\n2. Look for a weapon to fight back with.\n\n>>> ");
            scanf("%d", &choice);
            if (choice == 1)
            {
              hp(2);
              while (1)
              {
                system("clear");
                displayUI();
                printf("You manage to successfully dodge the majority of the guard’s strikes as you escape; however, you don’t escape completely unscathed and sustain some heavy damage. (-2 HP).\n\n1. Proceed to the first room.\n\n>>> ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                  room1();
                }
                else
                {
                  continue;
                }
              }
            }
            if (choice == 2)
            {
              while (1)
              {
                system("clear");
                inventoryAdd(0);
                displayUI();
                printf("You grab the item you spotted earlier in your cell and successfully use it against the guard, knocking him unconscious with a magnificent fireball! (Fireball Rune Unlocked!)\n\n1. Proceed to the first room.\n\n>>> ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                  room1();
                }
                else
                {
                  continue;
                }
              }
            }
          }
        }
        else
        {
          continue;
        }
      }
    }
    if (choice == 2)
    {
      while (1)
      {
        system("clear");
        displayUI();
        printf("You bang on the bars of the cell in an attempt to get the guard’s attention. As he walks over and tells you to be quiet, you notice his keys dangling from his pocket.\n\n1. You reach for the guard’s keys sneakily.\n2. Attack the guard in anger.\n\n>>> ");
        scanf("%d", &choice);
        if (choice == 1)
        {
          while (1)
          {
            chance = (rand() % 2) + 1;
            if (chance == 1)
            {
              while (1)
              {
                system("clear");
                inventoryAdd(0);
                displayUI();
                printf("You succeed in stealing the guard’s keys without him noticing! You grab the item you saw earlier, quickly unlock your cell door and sneak out as soon as the guard is out of sight. (Fireball Rune Unlocked!)\n\n1. Proceed to the first room.\n\n>>> ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                  room1();
                }
                else
                {
                  continue;
                }
              }
            }
            if (chance == 2)
            {
              hp(2);
              while (1)
              {
                system("clear");
                inventoryAdd(0);
                displayUI();
                printf("The guard notices you attempting to steal his keys and pushes you back into your cell. However, you end up falling on the fiery rune you noticed in the corner, which explodes. You are now free from the cell and the guard is now unconscious, but you still sustain some heavy damage. (-2 HP) (Fireball Rune Unlocked!)\n\n1. Proceed to the first room.\n\n>>> ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                  room1();
                }
                else
                {
                  continue;
                }
              }
            }
            else
            {
              continue;
            }
          }
        }
        if (choice == 2)
        {
          while (1)
          {
            system("clear");
            printf("Out of anger of the guard telling you to be quiet, you grab his shirt and bang his head against the bars, knocking the guard out. You pick up his keys and step out of your cell.\n\n1. Proceed to the first room.\n\n>>> ");
            scanf("%d", &choice);
            if (choice == 1)
            {
              room1();
            }
            else
            {
              continue;
            }
          }
        }
        else
        {
          continue;
        }
      }
    }
    if (choice == 3)
    {
      while (1)
      {
        system("clear");
        displayUI();
        printf("You peer over the corner of the cell and see a rune emanating with fiery magic.\n\n1. Pick up and inspect the rune.\n2. Decide not to tamper with such volatile magic.\n\n>>> ");
        scanf("%d", &choice);
        if (choice == 1)
        {
          int chance = (rand() % 4) + 1;
          if (chance == 1)
          {
            hp(2);
            while (1)
            {
              system("clear");
              inventoryAdd(0);
              displayUI();
              printf("As you grab onto the rune, the engravings begin to glow. You had accidentally activated the rune, and the entire cell explodes in one fireball. While not completely unscathed, the guard is knocked out and you are free from the cell. (-2 HP) (Fireball Rune Unlocked!)\n\n1. Proceed to the first room.\n\n>>> ");
              scanf("%d", &choice);
              if (choice == 1)
              {
                room1();
              }
              else
              {
                continue;
              }
            }
          }
          else
          {
            while (1)
            {
              system("clear");
              inventoryAdd(0);
              displayUI();
              printf("You grab the rune and inspect its engravings. From somewhere inside your memory, you realize that the engravings signifies that this rune casts a spell to create fireballs. (Fireball Rune Unlocked!)\n\n1. Use the rune to shoot a giant fireball directly at the Guard.\n2. Use the rune to create a small fireball that would break the lock.\n\n>>> ");
              scanf("%d", &choice);
              if (choice == 1)
              {
                hp(1);
                while (1)
                {
                  system("clear");
                  displayUI();
                  printf("When you attempt to shoot a giant fireball at the Guard, you underestimate the size of the fireball’s explosion. The guard is charred to a crisp, but you’re also in a not-so-perfect condition. Luckily, the cell now has a hole that you can escape from. (-1 HP)\n\n1. Proceed to the first room.\n\n>>> ");
                  scanf("%d", &choice);
                  if (choice == 1)
                  {
                    room1();
                  }
                  else
                  {
                    continue;
                  }
                }
              }
              if (choice == 2)
              {
                while (1)
                {
                  system("clear");
                  displayUI();
                  printf("Deciding that you don’t feel like murdering a random person in cold blood, you sneakily break the lock on the cell. While the guard isn’t looking, you silently sprint to the door.\n\n1. Proceed to the first room.\n\n>>> ");
                  scanf("%d", &choice);
                  if (choice == 1)
                  {
                    room1();
                  }
                  else
                  {
                    continue;
                  }
                }
              }
            }
          }
        }
        if (choice == 2)
        {
          hp(4);
          while (1)
          {
            system("clear");
            displayUI();
            printf("You decide to leave the magical rune where it is. Now back at square one, you thought about trying one of your other options… until you accidentally trip on a conveniently placed banana peel on the floor of the cage and land on top of the rune. It creates a fiery explosion that envelops the entire room. While you’re not dead, you are definitely worse for wear. On the bright side, the cage is broken… but so is the rune. (-4 HP)\n\n1. Proceed to the first room.\n\n>>> ");
            scanf("%d", &choice);
            if (choice == 1)
            {
              room1();
            }
            else
            {
              continue;
            }
          }
        }
        else
        {
          continue;
        }
      }
    }
    else
    {
      continue;
    }
  }
}

void room1() //Code for the first Room
{
  while (1) //narratives and options for the boss fight in the fight room
  {
    if (inventory[0] == 1)
    {
      system("clear");
      inventoryAdd(1);
      displayUI();
      printf("You cautiously walk into the first room in the dungeon. Unexpectedly, it’s almost…empty. The room is a dim but clean square room with nothing but a pedestal in the middle. On the pedestal is a rune, the engravings making you realize that it controls ice. Upon picking the rune up, three banners fall on the walls, each portraying a different monster. (Ice Rune Unlocked!)\n\n");
    }
    else
    {
      system("clear");
      inventoryAdd(0);
      inventoryAdd(1);
      displayUI();
      printf("You cautiously walk into the first room in the dungeon. Unexpectedly, it’s almost…empty. The room is a dim but clean square room with nothing but two pedestals in the middle. On each pedestal is a rune; one Fire, one Ice. Upon picking the runes up, three banners fall on the walls, each portraying a different monster. (Ice Rune Unlocked!) (Fireball Rune Unlocked!)\n\n");
    }
    printf("1. Touch the banner portraying a skeletal pirate.\n2. Touch the banner portraying an undead necromancer.\n3. Touch the banner portraying a stoic golem.\n\n>>> ");
    scanf("%d", &choice);
    if (choice == 1)
    {
      boss = 1;
      goto pirate; //goes to the pirate fight and begins it
    }
    if (choice == 2)
    {
      boss = 2;
      goto necromancer; //goes to the necromancer fight and begins it
    }
    if (choice == 3)
    {
      boss = 3;
      goto golem; //goes to the golem fight and begins it
    }
  }

  while (1) //narratives for the boss spawning for each boss fight
  {
    pirate: 
    system("clear");
    displayUI();
    printf("With a flash that makes you stumble back in surprise, a skeletal pirate holding a razor - sharp cutlass begins emerging from the banner. You quickly step back, aiming your runes at the unfazed pirate.\n\n1. Start\n\n>>> ");
    scanf("%d", &choice);
    if (choice != 1)
    {
      system("clear");
      continue;
    }
    else
    {
      system("clear");
      break;
    }

    necromancer:
    system("clear");
    displayUI();
    printf("With a flash that makes you stumble back in surprise, a cloaked necromancer with shadows obscuring his features begins emerging from the banner. You quickly step back as eerie chanting fills the room.\n\n1. Start\n\n>>> ");
    scanf("%d", &choice);
    if (choice != 1)
    {
      system("clear");
      continue;
    }
    else
    {
      system("clear");
      break;
    }

    golem:
    system("clear");
    displayUI();
    printf("With a flash that makes you stumble back in surprise, a massive stone golem begins emerging from the impossibly small banner. You quickly step back as the golem steps out with a booming rumble.\n\n1. Start\n\n>>> ");
    scanf("%d", &choice);
    if (choice != 1)
    {
      system("clear");
      continue;
    }
    else
    {
      system("clear");
      break;
    }
  }


  while (1) //goes to each boss attack/player attack
  {
    battle:  

    system("clear");
    if (turn % 2 == 0)
    {
      goto playerAttack;
    }
    if (turn % 2 != 0)
    {
      if (boss == 1)
      {
        goto pirateAttack;
      }
      if (boss == 2)
      {
        goto necromancerAttack;
      }
      if (boss == 3)
      {
        goto golemAttack;
      }
    }
  }

  pirateAttack: //all pirate attacks and what they do
  chance = (rand() % 6) + 1;
  switch(chance)
  {
    case 1:
    {
      if (dodge != 1)
        hp(1);
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("The pirate dashes over to you in the blink of an eye, slashing you across the chest with its cutlass. (-1 HP)\n\n");
      if (dodge == 1)
      {
        printf("Luckily, you dodged the attack!\n\n");
        sleep(3);
        dodge = 0;
      }
      sleep(5);
      if (health <= 0)
        gameOver();
      turn++;
      goto battle;
      break;
    }
    case 2:
    {
      if (dodge != 1)
        hp(1);
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("The pirate pulls out a vintage pistol, firing two shots at you in rapid succession. (-1 HP).\n\n");
      if (dodge == 1)
      {
        printf("Luckily, you dodged the attack!\n\n");
        sleep(3);
        dodge = 0;
      }
      sleep(5);
      if (health <= 0)
        gameOver();
      turn++;
      goto battle;
      break;
    }
    case 3:
    {
      if (dodge == 1)
        dodge = 0;
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("Pulling a tattered net out of seemingly nowhere, the pirate tosses it onto you, trapping you temporarily. (Skips your turn!)\n\n");
      sleep(5);
      if (health <= 0)
        gameOver();
      goto battle;
      break;
    }
    case 4:
    {
      if (dodge == 1)
        dodge = 0;
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("The pirate takes a few steps back without doing anything, seemingly sizing you up.\n\n");
      sleep(5);
      if (health <= 0)
        gameOver();
      turn++;
      goto battle;
      break;
    }
    case 5:
    {
      if (dodge != 1)
      {
        DOT(1, 100, 0);
        stopRune(1);
      }
      battleUI();
      displayUI();
      printf("The pirate suddenly pulls out a fiery grenade, launching it at you. The aftermath of the explosion leaves you on fire, dealing damage over time. (-1 HP per turn!) (Prevents you from using Ice Rune!)\n\n");
      if (dodge == 1)
      {
        printf("Luckily, you dodged the attack!\n\n");
        sleep(3);
        dodge = 0;
      }
      sleep(5);
      if (health <= 0)
        gameOver();
      turn++;
      goto battle;
      break;
    }
    case 6:
    {
      if (dodge == 1)
        dodge = 0;
      DOT(0, 0, 0);
      if (bossUlt == 0)
      {
        battleUI();
        displayUI();
        printf("The pirate suddenly stops moving, seemingly charging up a massive attack. A large, ghostly cannon forms in front of the pirate.\n\n");
        bossUlt++;
      }
      else
      {
        DOT(1, 3, 0);
        if (health <= 0)
          gameOver();
        battleUI();
        displayUI();
        printf("The ghostly cannon fires a burning fireball at you that's too fast to dodge. (-1 HP for the next three turns!)\n\n");
      }
      sleep(5);
      if (health <= 0)
        gameOver();
      turn++;
      goto battle;
      break;
    }
  }

  necromancerAttack: //displays all necromancer attacks and what they do
  chance = (rand() % 6) + 1;
  switch(chance)
  {
    case 1:
    {
      if (dodge == 1)
        dodge = 0;
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("The necromancer raises its cloaked arms, chanting. You’re forced to take your attention off the necromancer for a turn and eliminate the zombie that emerges from the ground. (Skips your turn!)\n\n");
      sleep(5);
      if (health <= 0)
        gameOver();
      checkFireball--;
      goto battle;
      break;
    }
    case 2:
    {
      if (dodge != 1)
        hp(1);
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("A shadowy tendril stretches out of the ground and grabs your leg, launching you across the room and flying into a wall. (-1 HP)\n\n");
      if (dodge == 1)
      {
        printf("Luckily, you dodged the attack!\n\n");
        sleep(3);
        dodge = 0;
      }
      sleep(5);
      if (health <= 0)
        gameOver();
      checkFireball--;
      turn++;
      goto battle;
      break;
    }
    case 3:
    {
      if (dodge != 1)
        hp(1);
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("Shadows begin coalescing around the necromancer’s hand, and a swirling, black orb forms and fires at you. (-1 HP)\n\n");
      if (dodge == 1)
      {
        printf("Luckily, you dodged the attack!\n\n");
        sleep(3);
        dodge = 0;
      }
      sleep(5);
      if (health <= 0)
        gameOver();
      checkFireball--;
      turn++;
      goto battle;
      break;
    }
    case 4:
    {
      if (dodge == 1)
        dodge = 0;
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("The necromancer backs up without attacking, seemingly having to prepare its next attack.\n\n");
      sleep(5);
      if (health <= 0)
        gameOver();
      checkFireball--;
      turn++;
      goto battle;
      break;
    }
    case 5:
    {
      if (dodge == 1)
        break;
      else
        DOT(1, 100, 0);
      battleUI();
      displayUI();
      printf("A zombie emerges from the ground behind, biting you on the shoulder and infecting you. (-1 HP per turn)\n\n");
      if (dodge == 1)
      {
        printf("Luckily, you dodged the attack!\n\n");
        sleep(3);
        dodge = 0;
      }
      sleep(5);
      if (health <= 0)
        gameOver();
      checkFireball--;
      turn++;
      goto battle;
      break;
    }
    case 6:
    {
      if (dodge != 1)
        hp(necromancerUlt);
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("Eerie chanting fills the room once again, and a skeleton emerges from the ground, shooting ghostly skulls at you. (Hint: Don't let them stack up! -%d HP!)\n\n", necromancerUlt);
      if (dodge == 1)
      {
        printf("Luckily, you dodged the attack(s)!\n\n");
        sleep(3);
        dodge = 0;
      }
      necromancerUlt++;
      sleep(5);
      if (health <= 0)
        gameOver();
      checkFireball--;
      turn++;
      goto battle;
      break;
    }
  }

  golemAttack: //displays all golem attacks and what they do
  chance = (rand() % 6) + 1;
  switch(chance)
  {
    case 1:
    {
      if (dodge == 1)
      {        
        ultChance = (rand() % golemUlt) + 1;
        if (ultChance == 1)
          dodge = 0;
      }
      stopRune(1);
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("The golem slams into the ground, sending a shockwave that knocks the Ice Rune out of your hands, preventing you from using the rune until you pick it up. (Ice Rune is gone for two turns!)\n\n");
      sleep(5);
      if (health <= 0)
        gameOver();
      turn++;
      goto battle;
      break;
    }
    case 2: //this messy code below is because of the golem's splitting ability; it reduces the dodge chance for each split and increases double damage chance for each split
    {
      if (dodge == 1) 
      {        
        ultChance = (rand() % golemUlt) + 1;
        if (ultChance == 1)
          dodge = 1;
        else
        {
          ultChance = (rand() % 4) + 1;
          if (ultChance > golemDD)
          {
            hp(2);
            dodge = 0;
          }
          else
          {
            hp(1);
            dodge = 0;
          }
        }
      }
      else
      {
        ultChance = (rand() % 4) + 1;
        if (ultChance > golemDD)
          hp(2);
        else
          hp(1);
      }
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("The golem charges towards you and rams into you, launching you into a wall with a bang. (-1 HP)\n\n");
      if (dodge == 1)
      {
        printf("Luckily, you dodged the attack!\n\n");
        sleep(3);
        dodge = 0;
      }
      sleep(5);
      if (health <= 0)
        gameOver();
      turn++;
      goto battle;
      break;
    }
    case 3:
    {
      if (dodge == 1)
      {        
        ultChance = (rand() % golemUlt) + 1;
        if (ultChance == 1)
          dodge = 1;
        else
        {
          ultChance = (rand() % 4) + 1;
          if (ultChance > golemDD)
          {
            hp(2);
            dodge = 0;
          }
          else
          {
            hp(1);
            dodge = 0;
          }
        }
      }
      else
      {
        ultChance = (rand() % 4) + 1;
        if (ultChance > golemDD)
          hp(2);
        else
          hp(1);
      }
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("Swinging its massive stone limbs at you, the attack connects, sending you flying across the room. (-1 HP)\n\n");
      if (dodge == 1)
      {
        printf("Luckily, you dodged the attack!\n\n");
        sleep(3);
        dodge = 0;
      }
      sleep(5);
      if (health <= 0)
        gameOver();
      turn++;
      goto battle;
      break;
    }
    case 4:
    {
      if (dodge == 1)
      {        
        ultChance = (rand() % golemUlt) + 1;
        if (ultChance == 1)
          dodge = 0;
      }
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("The golem attempts to lumber towards you to strike you again, but it’s too slow. Despite the golem’s attempts, you deftly stay out of its range.\n\n");
      sleep(5);
      if (health <= 0)
        gameOver();
      turn++;
      goto battle;
      break;
    }
    case 5:
    {
      if (dodge == 1)
      {        
        ultChance = (rand() % golemUlt) + 1;
        if (ultChance == 1)
          dodge = 0;
      }
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("With a massive cracking noise, the golem splits into two smaller, more agile golems. (-50%% player dodge chance, +25%% percent golem double damage chance!)\n\n");
      golemUlt *= 2;
      golemDD++;
      sleep(5);
      if (health <= 0)
        gameOver();
      turn++;
      goto battle;
      break;
    }
    case 6:
    {
      if (dodge == 1)
      {        
        ultChance = (rand() % golemUlt) + 1;
        if (ultChance == 1)
          dodge = 0;
      }
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("Two massive stone spikes burst from the ground, pinning you against the wall temporarily. (Skips your turn!)\n\n");
      sleep(5);
      if (health <= 0)
        gameOver();
      goto battle;
      break;
    }
  }

  playerAttack: //displays the player attacks choice, displays the attacks for each different boss

  while (1)
  {
    system("clear");
    battleUI();
    displayUI();
    printf("Attacks:\n1. Use your Fireball Rune.\n2. Use your Ice Rune.\n3. Attempt to dodge whatever attack they might throw at you.\n\n>>>  ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 3)
    {
      break;
    }
    else
    {
      continue;
    }
  }

  system("clear");


  if (boss == 1)
  {
    switch(choice)
    {
      case 1:
        if (inventory[0] != 0)
        {
          bosshp--;
        }
        if (bosshp <= 0)
          goto death;
        DOT(0, 0, 0);
        battleUI();
        displayUI();
        if (inventory[0] != 0)
        {
          printf("You activate your Fireball Rune, launching a fiery ball at the pirate. (+1 Damage!)\n\n");
        }
        else
        {
          printf("Sorry, you can't use that rune right now!\n\n");
          sleep(5);
          goto battle;
        }
        sleep(5);
        turn++;
        goto battle;
        break;  
      case 2:
        DOT(0, 0, 0);
        battleUI();
        displayUI();
        if (inventory[1] != 0)
        {
          printf("You activate your Ice Rune, freezing the pirate in a gust of glacial wind. (Skips the pirate’s turn!)\n\n");
        }
        else
        {
          printf("Sorry, you can't use that rune right now!\n\n");
          sleep(5);
          goto battle;
        }
        sleep(5);
        goto battle;
        break;
      case 3:
        DOT(0, 0, 0);
        battleUI();
        displayUI();
        printf("Acting on a gut feeling that the pirate will attack, you attempt to dodge whatever it’ll throw at you. (Negates the bad effect if the pirate DOES attack)\n\n");
        sleep(5);
        dodge = 1;
        turn++;
        goto battle; 
        break;
    }
  }
  if (boss == 2)
  {
    switch(choice)
    {
      case 1:
        if (checkFireball == 1 && necromancerUlt >= 1)
        {
          ultChance = (rand() % 2) + 1;
          if (ultChance == 1)
          {
            bosshp--;
          }
          else if (ultChance == 2)
          {
            necromancerUlt--;
            printf("You activate your Fireball, launching a fiery ball at the necromancer. However, a skeleton from earlier jumps in your way, blocking your attack.\n\n");
          }
        }
        else
        {
          bosshp--;
          if (bosshp <= 0)
            goto death;
          DOT(0, 0, 0);
          battleUI();
          displayUI();
          if (inventory[0] != 0)
          {
            printf("You activate your Fireball Rune, launching a fiery ball at the necromancer. (+1 Damage!)\n\n");
              checkFireball++;
          }
          else
          {
            printf("Sorry, you can't use that rune right now!\n\n");
            sleep(5);
            goto battle;
          }
          sleep(5);
          turn++;
          goto battle;
          break;
        }
      case 2:
        DOT(0, 0, 0);
        battleUI();
        displayUI();
        if (inventory[1] != 0)
        {
        printf("You activate your Ice Rune, freezing the necromancer in a gust of glacial wind. (Skips the necromancer’s turn!)\n\n");
        }
        else
        {
          printf("Sorry, you can't use that rune right now!\n\n");
          sleep(5);
          goto battle;
        }
        sleep(5);
        goto battle;
        break;
      case 3:
        DOT(0, 0, 0);
        battleUI();
        displayUI();
        printf("Acting on a gut feeling that the necromancer will attack, you attempt to dodge whatever it’ll throw at you. (Negates the bad effect if the necromancer DOES attack)\n\n");
        sleep(5);
        dodge = 1;
        turn++;
        goto battle;
        break;
    }
  }
  if (boss == 3)
  {
    switch(choice)
    {
      case 1:
        bosshp--;
        if (bosshp <= 0)
          goto death;
        DOT(0, 0, 0);
        battleUI();
        displayUI();
        if (inventory[0] != 0)
        {
        printf("You activate your Fireball Rune, launching a fiery ball at the golem. (+1 Damage!)\n\n");
        }
        else
        {
          printf("Sorry, you can't use that rune right now!\n\n");
          sleep(5);
          goto battle;
        }
        sleep(5);
        turn++;
        goto battle;
        break;
      case 2:
        DOT(0, 0, 0);
        battleUI();
        displayUI();
        if (inventory[1] != 0)
        {
        printf("You activate your Ice Rune, freezing the golem in a gust of glacial wind. (Skips the golem’s turn!)\n\n");
        }
        else
        {
          printf("Sorry, you can't use that rune right now!\n\n");
          sleep(5);
          goto battle;
        }
        sleep(5);
        goto battle;
        break;
      case 3:
        DOT(0, 0, 0);
        battleUI();
        displayUI();
        printf("Acting on a gut feeling that the golem will attack, you attempt to dodge whatever it’ll throw at you. (Negates the bad effect if golem DOES attack)\n\n");
        sleep(5);
        dodge = 1;
        turn++;
        goto battle;
        break;
    }
  }

  death: //displays the death screen for each bosses death

  system("clear");

  if (boss == 1)
  {
    while (1)
    {
      DOT(0, -1, 0);
      inventory[0] = 1;
      inventory[1] = 1;
      printf("Finally, after your long and arduous fight with the skeletal pirate, the pirate crumbles into a pile of bones. You stand victorious as a hidden door slides open, revealing the path to room two.\n\n1. Proceed to the second room.\n\n>>> ");
      scanf("%d", &choice);
      if (choice == 1)
      {
        room2();
      }
    }
  }
  if (boss == 2)
  {
    while (1)
    {
      DOT(0, -1, 0);
      inventory[0] = 1;
      inventory[1] = 1;
      printf("Upon landing the final blow on the necromancer, the necromancer crumbles into a pile of dust. You stand victorious as a hidden door slides open, revealing the exit to the room.\n\n1. Proceed to the second room.\n\n>>> ");
      scanf("%d", &choice);
      if (choice == 1)
      {
        room2();
      }
    }
  }
  if (boss == 3)
  {
    while (1)
    {  
      DOT(0, -1, 0);
      inventory[0] = 1;
      inventory[1] = 1;
      printf("Finally, you land a lethal blow on the golem, eliminating it for good. The golem crumbles into a pile of broken rocks, leaving you standing as the lone victor.\n\n1. Proceed to the second room.\n\n>>> ");
      scanf("%d", &choice);
      if (choice == 1)
      {
        room2();
      }
    }
  }
}

void room2() //Code for the second Room
{
  while (1) //displays the narratives for the second room, gives the player their choices
  {
    system("clear");
    printf("Upon entering the second room, you grimace as an unpleasant smell enters your nose and a dim, flickering neon light makes you squint. You look around the room, and your eyes widen in horror as you observe a multitude of caged beasts attempting to reach you from their cages.\n\n1. Try to run through the room.\n2. Blow up the creatures with your new rune.\n3. Try to escape back to your cell.\n\n>>> ");
    scanf("%d", &choice);
    if (choice == 1)
    {
      while (1)
      {
        system("clear");
        displayUI();
        printf("You attempt to run out the room to the door in the distance, but you trip over a small object halfway. Upon investigating, you realize that it’s another rune; however, before you’re able to decipher what this one does, a creature manages to break out of its cage with a bang, leaping towards you.\n\n1. Try your new rune.\n2. Use your Fireball Rune.\n\n>>> ");
        scanf("%d", &choice);
        if (choice == 1)
        {
          while (1)
          {
            system("clear");
            inventoryAdd(2);
            displayUI();
            printf("You take the risk and activate your newly acquired rune. To your astonishment, a bolt of lightning shoots from the rune and strikes the creature, eliminating it in one blow. (Lightning Rune Unlocked!)\n\n1. Proceed to the third room.\n\n>>> ");
            scanf("%d", &choice);

            if (choice == 1)
            {
              room3();
            }
            else
            {
              continue;
            }
          }
        }
        if (choice == 2)
        {
          hp(1);
          while (1)
          {
            system("clear");
            inventoryAdd(2);
            displayUI();
            printf("You attempt to activate your trusty Fireball Rune, but the creature strikes your arm, knocking it out of your hand. With no other choice, you activate your new rune. To your amazement, a bolt of lightning strikes the creature, eliminating it instantly. (-1 HP) (Lightning Rune Unlocked!)\n\n1. Proceed to the third room.\n\n>>> ");

            if (choice == 1)
            {
              room3();
            }
            else
            {
              continue;
            }
          }
        }
        else
        {
          continue;
        }
      }
    }
    if (choice == 2)
    {
      while (1)
      {
        system("clear");
        inventoryAdd(2);
        displayUI();
        printf("You whip your newly acquired Fireball Rune out and point it towards the nearest cage. Upon blowing it up and killing the monster, you notice another rune glinting in the now charred cage and pick it up. (Lightning Rune Unlocked!)\n\n1. Try your new rune out right here.\n2. Leave the room first.\n\n>>> ");    
        scanf("%d", &choice);
        if (choice == 1)
        {
          system("clear");
          displayUI();
          printf("You decide to try out your new rune before going anywhere else. While still in the charred cage, you activate the Lightning Rune. To your astonishment, it shoots out a bolt of lightning which ends up striking the cage; however, your amazement quickly turns to horror as the lightning jumps from cage to cage, breaking them and releasing the creatures.\n\n");
          break;
        }
        if (choice == 2)
        {
          system("clear");
          displayUI();
          printf("You decide to wait until you leave the dangerous room before trying out your new rune. However, as soon as you step out of the cage, you notice the growls sound a lot closer than before. The creatures have escaped from their cells.\n\n");
          break;
        }
        else
        {
          continue;
        }
      }
      while (1)
      {
        printf("1. Stand your ground and fight the monsters.\n2. Try to escape before the monsters react.\n\n>>> ");
        scanf("%d", &choice);
        if (choice == 1)
        {
          while (1)
          {
            system("clear");
            displayUI();
            printf("Wielding your Fireball, Ice, and Lightning runes, you stand your ground and face the approaching monsters. Thinking fast, you quickly freeze them with your Ice Rune before they can attack you.\n\n1. Finish them off with your trusty Fireball Rune.\n2. Finish them off with your new Lightning Rune.\n\n>>> ");
            scanf("%d", &choice);
            if (choice == 1)
            {
              hp(1);
              while (1)
              {
                system("clear");
                displayUI();
                printf("You fire a massive fireball towards the monsters, hoping to take them out in one blow. However, while you manage to eliminate the majority of them, a few, surviving due to their icy encasings, swipe at you while you run to the exit. (-1 HP).\n\n1. Proceed to the third room.\n\n>>> ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                  room3();
                }
                else
                {
                  continue;
                }
              }
            }
            if (choice == 2)
            {
              while (1)
              {
                system("clear");
                displayUI();
                printf("You decide to test just how powerful your new Lightning Rune is. Activating it, a bolt of lightning streaks out, jumping from creature to creature, and leaving nothing but corpses behind.\n\n1. Proceed to the third room.\n\n>>> ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                  room3();
                }
                else
                {
                  continue;
                }
              }
            }
          }
        }
        if (choice == 2)
        {
          hp(1);
          while (1)
          {
            system("clear");
            displayUI();
            printf("You bolt towards the exit immediately in hopes you can get there before the monsters react. As you near the exit, a creature slams you into a cell, blocking off your path to the exit. (-1 HP).\n\n1. Take the last couple steps to the exit.\n2. Use your runes to kill everything in your way.\n\n>>> ");
            scanf("%d", &choice);
            if (choice == 1)
            {
              hp(1);
              while (1)
              {
                system("clear");
                displayUI();
                printf("Ducking and swiping, you attempt to run the final, tiny stretch to the exit. Somehow, out of sheer luck, you make it because most of the monsters are behind you, but you don’t escape unharmed. (-1 HP).\n\n1. Proceed to the third room.\n\n>>> ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                  room3();
                }
                else
                {
                  continue;
                }
              }
            }
            if (choice == 2)
            {
              hp(1);
              while (1)
              {
                system("clear");
                displayUI();
                printf("You decide to resort to violence and not leave anything in your wake. Activating all your runes at once as to not give the monsters any chance of survival, the room is consequently engulfed in flames, ice, and lightning. While you did succeed in killing all the monsters, your reckless actions injured you, too. (-1 HP).");
                scanf("%d", &choice);
                if (choice == 1)
                {
                  room3();
                }
                else
                {
                  continue;
                }
              }
            }
            else
            {
              continue;
            }
          }
        }
        else
        {
          continue;
        }
      }
    }
    if (choice == 3)
    {
      while (1)
      {
        system("clear");
        displayUI();
        printf("As soon as you turn around, the door slams down with a bang. Even worse, you hear the growls getting closer behind you, and, as you turn around, you realize the creatures have escaped.\n\n1. Attempt to run through the monsters before they react.\n2. Use your Fireball Rune.\n\n>>> ");
        scanf("%d", &choice);
        if (choice == 1)
        {
          hp(2);
          while (1)
          {
            system("clear");
            displayUI();
            printf("You attempt to run through the monsters, and you manage to make it halfway across the room before getting knocked down to the ground. Desperately grabbing around randomly, you happen to not only grab a slightly familiar, small object that was on the ground but you manage to pull out your Fireball Rune and Ice Rune as well. (-2 HP)\n\n1. Fire your trusty Fireball at the monsters.\n2. Freeze the monsters with your Ice Rune.\n3. Take a risk and use the object you grabbed.\n\n>>> ");
            scanf("%d", &choice);
            if (choice == 1)
            {
              hp(1);
              while (1)
              {
                system("clear");
                inventoryAdd(2);
                displayUI();
                printf("Activating your Fireball Rune to its fullest extent, a massive fireball engulfs the room, taking out all the monsters in one blow; however, you acknowledge that you aren’t unscathed either as you hobble out of the room, grasping the rune you found on the floor tightly. (-1 HP) (Lightning Rune Unlocked!)\n\n1. Proceed to the third room.\n\n>>> ");
                if (choice == 1)
                {
                  room3();
                }
                else
                {
                  continue;
                }
              }
            }
            if (choice == 2)
            {
              while (1)
              {
                system("clear");
                inventoryAdd(2);
                displayUI();
                printf("You activate your Ice Rune, completely engulfing the majority of the monsters in freezing, cold ice. While the beasts are still frozen, you scramble back onto your feet and activate the object you found on the floor, finishing them off with a bolt of lightning. (Lightning Rune Unlocked!)\n\n1. Proceed to the third room.\n\n>>> ");

                if (choice == 1)
                {
                  room3();
                }
                else
                {
                  continue;
                }
              }
            }
            if (choice == 3)
            {
              while (1)
              {
                system("clear");
                inventoryAdd(2);
                displayUI();
                printf("You decide to take a massive risk and attempt to use the object you randomly grabbed. To your astonishment, a blinding bolt of lightning shoots out and strikes the monsters. You quickly run to the exit while they’re stunned. (Lightning Rune Unlocked!)\n\n1. Proceed to the third room.\n\n>>> ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                  room3();
                }
                else
                {
                  continue;
                }
              }
            }
            else
            {
              continue;
            }
          }
        }
        if (choice == 2)
        {
          while (1)
          {
            system("clear");
            displayUI();
            printf("Staying calm, you pull your Fireball Rune out and aim it at the approaching beasts. A massive, fiery fireball shoots out towards the monsters as you activate it, but the majority of them continue approaching unfazed.\n\n1. Continue to fire Fireballs at the monsters.\n2. Change it up and freeze the monsters.\n3. Look for a better way to kill the monsters.\n\n>>> ");
            scanf("%d", &choice);
            if (choice == 1)
            {
              while (1)
              {
                system("clear");
                displayUI();
                printf("You continue relentlessly firing your fireballs at the approaching monsters. While you are managing to take down a decent chunk of them, the creatures are still gaining distance towards you.\n\n1. Take a different approach and use your Ice Rune.\n2. Continue firing fireballs as they are managing to kill the monsters.\n\n>>> ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                  system("clear");
                  displayUI();
                  printf("Deciding to change up your strategy, you begin alternating between your Ice and Fireball Rune. The new tactic works, and the beasts begin falling before you, unable to approach without being frozen and burnt. Eventually, the room is silent except for the sound of your own breathing.\n\n1. Begin walking towards the exit.\n2. Search the room for anything of value.\n\n>>> ");
                  scanf("%d", &choice);
                  if (choice == 1)
                  {
                    while (1)
                    {
                      system("clear"); 
                      inventoryAdd(2);
                      displayUI();
                      printf("Deciding to get out of the room as fast as possible, you quickly stride towards the exit. However, unexpectedly, you trip over a small object partway through the room. Upon investigating, you realize that it’s a rune, crackling with electric energy. (Lightning Rune Unlocked!)\n\n1. Proceed to the third room.\n\n>>> ");
                      scanf("%d", &choice);
                      if (choice == 1)
                      {
                        room3();
                      }
                      else
                      {
                        continue;
                      }
                    }
                  }
                  if (choice == 2)
                  {
                    while (1)
                    {
                      system("clear");   
                      inventoryAdd(2);
                      displayUI();
                      printf("Seeing that there is no imminent danger anymore, you decide to take a look around the place to see if there is anything of use. After a couple of minutes, you notice a small, familiar - looking object gleaming in the center of the room. You quickly realize that it’s another rune, and pick it up before heading towards the exit. (Lightning Rune Unlocked!)\n\n1. Proceed to the third room.\n\n>>> ");
                      scanf("%d", &choice);
                      if (choice == 1)
                      {
                        room3();
                      }
                      else
                      {
                        continue;
                      }
                    }
                  }
                }
                if (choice == 2)
                {
                  while (1)
                  {
                    system("clear");
                    displayUI();
                    printf("Finally, despite your relentless fireballs, the creatures reach you, reaching out and striking you with their long claws. However, with one final burst of energy, you fire one final, massive fireball, engulfing the whole room in flame, and leaving you barely alive. (-2 HP)\n\n1. Begin walking towards the exit.\n2. Search the room for anything of value.\n\n>>> ");
                    scanf("%d", &choice);
                    if (choice == 1)
                    {
                      while (1)
                      {
                        system("clear"); 
                        inventoryAdd(2);
                        displayUI();
                        printf("Deciding to get out of the room as fast as possible, you quickly stride towards the exit. However, unexpectedly, you trip over a small object partway through the room. Upon investigating, you realize that it’s a rune, crackling with electric energy. (Lightning Rune Unlocked!)\n\n1. Proceed to the third room.\n\n>>> ");
                        scanf("%d", &choice);
                        if (choice == 1)
                        {
                          room3();
                        }
                        else
                        {
                          continue;
                        }
                      }
                    }
                    if (choice == 2)
                    {
                      while (1)
                      {
                        system("clear");  
                        inventoryAdd(2);
                        displayUI();
                        printf("Seeing that there is no imminent danger anymore, you decide to take a look around the place to see if there is anything of use. After a couple of minutes, you notice a small, familiar - looking object gleaming in the center of the room. You quickly realize that it’s another rune, and pick it up before heading towards the exit. (Lightning Rune Unlocked!)\n\n1. Proceed to the third room.\n\n>>> ");
                        scanf("%d", &choice);
                        if (choice == 1)
                        {
                          room3();
                        }
                        else
                        {
                          continue;
                        }
                      }
                    }
                  }
                }
              }
            }
            if (choice == 2)
            {
              while (1)
              {
                system("clear");
                displayUI();
                printf("You realize that the Fireball Rune isn’t working, so you take a different approach. Alternating between your Ice and Fire Runes, the beasts fall before your ingenious tactic and eventually, the room is silent except for the sound of your own breathing.\n\n1. Begin walking towards the exit.\n2. Search the room for anything of value.\n\n>>> ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                  while (1)
                  {
                    system("clear"); 
                    inventoryAdd(2);
                    displayUI();
                    printf("Deciding to get out of the room as fast as possible, you quickly stride towards the exit. However, unexpectedly, you trip over a small object partway through the room. Upon investigating, you realize that it’s a rune, crackling with electric energy. (Lightning Rune Unlocked!)\n\n1. Proceed to the third room.\n\n>>> ");
                    scanf("%d", &choice);
                    if (choice == 1)
                    {
                      room3();
                    }
                    else
                    {
                      continue;
                    }
                  }
                }
                if (choice == 2)
                {
                  while (1)
                  {
                    system("clear");
                    inventoryAdd(2);
                    displayUI();
                    printf("Seeing that there is no imminent danger anymore, you decide to take a look around the place to see if there is anything of use. After a couple of minutes, you notice a small, familiar - looking object gleaming in the center of the room. You quickly realize that it’s another rune, and pick it up before heading towards the exit. (Lightning Rune Unlocked!)\n\n1. Proceed to the third room.\n\n>>> ");
                    scanf("%d", &choice);
                    if (choice == 1)
                    {
                      room3();
                    }
                    else
                    {
                      continue;
                    }
                  }
                }
              }
            }
            if (choice == 3)
            {
              while (1)
              {
                system("clear");
                displayUI();
                printf("You acknowledge that you won’t be able to make it out of this encounter alive with your current runes. Quickly scanning around the room, you look for anything that could help you take down the beasts, and a glinting object, on the floor among all the creatures, catches your eye.\n\n1. Try to grab the object to see if it’s of value.\n2. Continue looking around for a safer option.\n\n>>> ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                  while (1)
                  {
                    system("clear");
                    inventoryAdd(2);
                    displayUI();
                    printf("You decide to recklessly dive for the gleaming object, not being able to avoid a few of the swiping claws of the creatures around it. Upon reaching the object, you activate it immediately, completely surrounded by monsters. To your astonishment, a burst of lightning streaks out, eliminating the creatures with ease. (-1 HP) (Lightning Rune Unlocked!)\n\n1. Proceed to the third room.\n\n>>> ");
                    scanf("%d", &choice);
                    if (choice == 1)
                    {
                      room3();
                    }
                    else
                    {
                      continue;
                    }
                  }
                }
                if (choice == 2)
                {
                  while (1)
                  {
                    system("clear");
                    displayUI();
                    printf("You continue to desperately look around the room, but to no avail. The monsters continue approaching you, and you’re running out of time.\n\n1. Make a last - ditch attempt to get the object lying amongst the creatures.\n2. Give up on finding something and use the runes you already have.\n\n>>> ");
                    if (choice == 1)
                    {
                      while (1)
                      {
                        system("clear");
                        displayUI();
                        printf("Knowing that you don’t have any choice, you dive recklessly amidst the monsters and grab the object. To your amazement, it’s a rune. You activate it immediately, and a bolt of lightning streaks out, killing the monsters in a powerful electric blow. (Lightning Rune Unlocked!)\n\n1. Proceed to the third room.\n\n>>> ");
                        scanf("%d", &choice);
                        if (choice == 1)
                        {
                          room3();
                        }
                        else
                        {
                          continue;
                        }
                      }
                    }
                    if (choice == 2)
                    {
                      while (1)
                      {
                        system("clear");
                        displayUI();
                        printf("Deciding not to risk diving amidst all the monsters for the object that you don’t even know the identity of, you quickly pull out your Fireball and Ice Runes to fight them. A long and arduous fight ensues, and you remain standing as the only living thing in the room by the end, albeit barely. (-3 HP)\n\n1. Begin walking towards the exit.\n2. Search the room for anything of value.\n\n>>> ");
                        scanf("%d", &choice);
                        if (choice == 1)
                        {
                          while (1)
                          {
                            system("clear"); 
                            inventoryAdd(2);
                            displayUI();
                            printf("Deciding to get out of the room as fast as possible, you quickly stride towards the exit. However, unexpectedly, you trip over a small object partway through the room. Upon investigating, you realize that it’s a rune, crackling with electric energy. (Lightning Rune Unlocked!)\n\n1. Proceed to the third room.\n\n>>> ");
                            scanf("%d", &choice);
                            if (choice == 1)
                            {
                              room3();
                            }
                            else
                            {
                              continue;
                            }
                          }
                        }
                        if (choice == 2)
                        {
                          while (1)
                          {
                            system("clear");   
                            inventoryAdd(2);
                            displayUI();
                            printf("Seeing that there is no imminent danger anymore, you decide to take a look around the place to see if there is anything of use. After a couple of minutes, you notice a small, familiar - looking object gleaming in the center of the room. You quickly realize that it’s another rune, and pick it up before heading towards the exit. (Lightning Rune Unlocked!)\n\n1. Proceed to the third room.\n\n>>> ");
                            scanf("%d", &choice);
                            if (choice == 1)
                            {
                              room3();
                            }
                            else
                            {
                              continue;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else
            {
              continue;
            }
          }
        }
        else
        {
          continue;
        }
      }
    }
  }
}

void room3() //Code for the third Room
{ 
  while (1) //displays the choices and options and dialogue for the third room + knight, goes kind of in a circle
  {
    system("clear");
    displayUI();
    printf("         :+:**- \n"); //ASCII art for the knight
    printf("       .:=-=*+.. \n");
    printf("      .=---- \n");    
    printf("       -+*=-. \n");
    printf("   ....--+=-::--. \n");
    printf("  ::::=--==--=--=-:= \n");
    printf("  :::==---::=---:-:- \n");
    printf(" --.:-=--:---==:-::-\n");    
    printf(" =+:--===::--::-:::- \n");
    printf(" -=---:+*::::--::::: \n");
    printf(" :---:.=+*-::----:::: \n");
    printf(" .:--..*+*=::-:::-::: \n");
    printf("  :--.-+**+-::-:-:-: \n");
    printf(" :::.-------::::-. \n");
    printf(" .:-:++--  ==*+- \n");
    printf("  :--++=.  -=*= \n");
    printf("  :-:---   .=-- \n");
    printf("  :-:=--    :-- \n");
    printf("  .-=*+:    :++. \n");
    printf(" .:====:    =+*+==== \n");
    printf("As you walk into the room, you hear a voice shout at you. ‘HALT!’ shouts the voice. You look towards the noise. It seems to be a knight blocking the exit door, wearing . ‘I STAND NIGHT AND DAY TO PREVENT ANY TRESPASSERS FROM ENTERING. TURN BACK OR TASTE MY BLADE.’\n\n1. Approach the knight.\n2. Use one of your runes on the knight.\n3. Ignore the exit door and knight for now and investigate the room.\n\n>>> ");
    scanf("%d", &choice);
    if (choice == 1)
    {
      while (1)
      {
        approach:

        system("clear");
        displayUI();
        printf("The knight tenses up when you move closer to him, as if getting ready to attack.\n\n1. Try to calm things down by talking to the knight.\n2. Strike with one of your runes before he gets the chance to go first.\n3. Sprint to the door.\n\n>>> ");
        scanf("%d", &choice);
        if (choice == 1)
        {
          while (1)
          {
            pacifist:

            system("clear");
            displayUI();
            printf("‘WAIT! I don’t want to fight,’ you say. You convince the knight that you have no intentions to trespass. ‘HMPH. FINE, YOU CAN STAY IN THIS ROOM AS LONG AS YOU DON’T GO NEAR THIS DOOR.’\n\n1. ‘Aren’t you tired of just protecting this door all day? Do you ever take a break?’\n2. ‘Could I prease go thru? I no spreak engrish good.’\n3. ‘Day and night? That’s a really long time to just be standing here.’\n\n>>> ");
            scanf("%d", &choice);
            if (choice == 1)
            {
              while (1)
              {
                doubtinquire:

                system("clear");  
                displayUI();
                printf("‘IF I DON’T HOLD MY PLACE HERE, I WILL FAIL MY LORD. I WILL NOT FAIL, I WILL NOT GIVE INTO TEMPTATIONS AND WEAKNESS. I WILL GUARD FOR ETERNITY IF I MUST.’\n\n1. ‘That sounds exhausting and impossible to keep up. Are you sure you don’t want to rest even for a little while?’\n2. ‘Well, I can’t stop you.’ Explore the rest of the room.\n\n>>> ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                  while (1)
                  {
                    system("clear");
                    displayUI();
                    printf("Upon hearing the question, the knight’s everlasting adrenaline had been interrupted for only a split second of hesitation, and they suddenly collapsed to the ground unmoving. They seem to have gone unconscious.\n\n1. Continue\n\n>>> ");
                    if (choice == 1)
                    {
                      while (1)
                      {
                        inspecttheknight:

                        system("clear");
                        inventoryAdd(3);
                        displayUI();
                        printf("Before going to the room, you notice the glowing light of a rune emanating from the Knight’s body. You go to pick it up from their person and suddenly feel newfound vitality and energy coursing through you. (Vitality Rune Unlocked!).\n\n1. Continue\n\n>>> ");
                        scanf("%d", &choice);
                        if (choice == 1)
                        {
                          finalRoom();
                        }
                      }
                    }
                  }
                }
                if (choice == 2)
                {
                  while (1)
                  {
                    ignoregiveup:

                    system("clear");
                    displayUI();
                    printf("The room was lavishly decorated like the interior of a castle’s banquet hall. And yet, there were no items of interest other than an out of place piece of paper. Unlike the runes, there doesn’t seem to be any magical energy emanating from it, but you don’t really have any other options.\n\n1. Ignore the piece of paper and just approach the knight.\n2. Pick up the note and read its contents.\n\n>>> ");
                    scanf("%d", &choice);
                    if (choice == 1)
                    {
                      goto approach;
                    }
                    if (choice == 2)
                    {
                      while (1)
                      {
                        system("clear");
                        displayUI();
                        printf("The note is as written: ‘As imposing as the knight is, there is an easy way to deal with them. The only thing giving them everlasting vitality is a rune inside their chestplate. If one finds a way to disable the rune, the knight will feel their exhaustion once again and fall. The easiest solution is to make the knight’s thoughts stray. The rune requires concentration to continue working.’\n\n1. With this newfound information, you approach the knight.\n\n>>> ");
                        scanf("%d", &choice);
                        if (choice == 1)
                        {
                          while (1)
                          {
                            system("clear");
                            displayUI();
                            printf("The knight tenses up when you move closer to him, as if getting ready to attack. You see the glowing rune upon their chest.\n\n1. Try to disable the rune by talking to the knight.\n2. Strike their chest with one of your own runes to try and break the rune.\n\n>>> ");
                            scanf("%d", &choice);
                            if (choice == 1)
                            {
                              goto pacifist;  
                            }
                            if (choice == 2)
                            {
                              while (1)
                              {
                                system("clear");
                                displayUI();
                                printf("Not exactly knowing which one would work the best, you just spam each of your runes against the knight like it is the first time you’ve played a fighting game. Turns out, it worked pretty well. The knight seems to be completely dealt with. Sadly, your spamming also seemed to have broken the rune. Oh well.\n\n1. Continue\n\n>>> ");
                                scanf("%d", &choice);
                                if (choice == 1)
                                {
                                  finalRoom();
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            if (choice == 2)
            {
              hp(1);
              while (1)
              {
                system("clear");
                displayUI();
                printf("‘HA! YOU MUST THINK I’M STUPID.’ The guard realizes your insincerity and goes in for the attack! (-1 HP)\n\n1. Retaliate with one of your runes!\n2. Try to evade him and bolt for the door.\n\n>>> ");
                scanf("%d", &choice);
                if (choice == 1)
                {
                  while (1)
                  {
                    fight:

                    system("clear");
                    displayUI();
                    printf("Which rune will you use?\n\n1. The Fiery Rune.\n2. The Cold Rune.\n3. The Sparkling Rune.\n\n>>> ");
                    scanf("%d", &choice);
                    if (choice == 1)
                    {
                      hp(3);
                      while (1)
                      {
                        system("clear");
                        displayUI();
                        printf("You retaliate with a ball of flames, enveloping the knight in a giant blaze. Learning your lesson, you stepped back far enough to not be hit by the explosion, but the knight’s sword hit your side. It seems like in their final moments, they threw their sword, hoping to take you down with them. (-3 HP)\n\n1. Continue\n\n>>> ");
                        scanf("%d", &choice);
                        if (choice == 1)
                        {
                          goto inspecttheknight;
                        }
                      }
                    }
                    if (choice == 2)
                    {
                      hp(2);
                      while (1)
                      {
                        system("clear");
                        displayUI();
                        printf("You attempt to freeze the knight, but you miscalculated and hit the ground instead. Luckily, the knight was doing a charge attack and slipped on the ice, falling on their sword and impaling themself in their chest. It was somewhat comedic, but it was also a gruesome sight. ‘Oh well, at least I’m unscathed,’ you think, as you trip on your own ice and knock your head on the ground. (-2 HP)\n\n1. Continue\n\n>>> ");
                        scanf("%d", &choice);
                        if (choice == 1)
                        {
                          goto inspecttheknight;
                        }
                      }
                    }
                    if (choice == 3)
                    {
                      hp(1);
                      while (1)
                      {
                        system("clear");
                        displayUI();
                        printf("You whip out your newly acquired rune and activate it, shooting bolts of lightning at the knight. The knight somehow deflects the bolts of lightning with ease as they approach you. Once they’re right in front of you, you attempt to shoot another lightning bolt–this time with maximum firepower–as the knight swings at you. They nicked your body, but your lightning bolt hit their chest as a parry. Like a conductor, the pallid armour spreads the lightning throughout the knight’s body, and they fall to the ground. (-1 HP)\n\n1. Continue\n\n>>> ");
                        scanf("%d", &choice);
                        if (choice == 1)
                        {
                          goto inspecttheknight;
                        }
                      }
                    }
                  }
                }
                if (choice == 2)
                {
                  run:

                  hp(3);
                  while (1)
                  {
                    system("clear");
                    displayUI();
                    printf("Trying to catch him off guard, you duck under his sword and sprint to the door. You try to open it but realize it’s locked. Panicking, you don’t even realize the knight had charged at you and rammed you into the door, breaking it. Some force is preventing the knight from going into the next room, so you watch as they glare at you from the previous room. (-3 HP)\n\n1. Continue.\n\n>>> ");
                    scanf("%d", &choice);
                    if (choice == 1)
                    {
                      finalRoom();
                    }
                  }
                }
              }
            }
            if (choice == 3)
            {
              goto doubtinquire;
            }
          }
        }
        if (choice == 2)
        {
          goto fight;
        }
        if (choice == 3)
        {
          goto run;
        }
      }
    }
    if (choice == 2)
    {
      goto fight;
    }
    if (choice == 3)
    {
      goto ignoregiveup;
    }
  }
}

void finalRoom() //Code for the final Room
{ 
  //Reset Variables
  bosshp = 11;
  turn = 0;
  dodge = 0;
  dmgPerTurn = 0;
  bossUlt = 0;
  bosscounter = 0;

  while (1) 
  {
    system("clear");
    printf("As you walk into the illuminated chamber, you see what looks to be a king in pallid armor. The king is unresponsive to your presence, glaring just past you with a look of contempt. You think to yourself, ‘Maybe I can just go past the man without any trouble,’ but that hope immediately dwindles as he speaks.\n\nYou. State your purpose.\n\n1. Continue\n\n>>> ");
    scanf("%d", &choice);
    if (choice != 1)
      continue;
    break;
  }

  while (1)
  {
    system("clear");
    printf("1. ‘I just woke up in a cell here. I mean no trouble.’\n2. ‘Why should I explain myself to you? You’re the one who probably took me in the first place.’\n3. ‘Can’t really say, I don’t really know why I’m here myself.'\n4. Attack\n\n>>> ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 3)
      goto scriptedfightwoo;
    if (choice == 4)
      goto startbattle;
    continue;
  }

  while (1)
  {
    scriptedfightwoo:  

    system("clear");
    printf("The king glares at you, judging your answer. ‘You’re wasting time. Precious time. I can feel the seconds of each who comes here. Not even a second can be wasted. If you want to leave, then you must fight me.’ He slowly gets up off the throne, ripping the bindings that held him down. The king raises his arm, and a sword of broken, pale glass manifests in his hand.\n\n1. Start\n\n>>> ");
    scanf("%d", &choice);
    if (choice != 1)
      continue;
    break;
  }

  startbattle: //starts the battle, displays boss screen

  system("clear");
  printf("==============\nTHE PALLID ONE\n==============\n\n");
  sleep(3);
  goto finalbattle;

  finalbattle:

  system("clear");
  if (turn % 2 == 0)
  {
    goto attack;
  }
  else
  {
    goto pallidAttack;
  }

  while (1) //player attacks choices and the attacks, and has the scenario for if the king does his taunt/reflect ability
  {
    attack:
    system("clear");
    chance = (rand() % 5) + 1;
    battleUI();
    displayUI();

    printf("Attacks:\n1. Activate your fireball rune against the king. (+1 damage per turn)\n2. Activate your ice rune to freeze the king. (Skips next turns)\n3. Activate your lightning rune and shoot bolts of lightning at the king. (+2 damage)\n4. Defend against attacks. (Chance to negate the next two attacks)");
    if (inventory[3] == 1)
    {
      printf("\n5. Concentrate on healing yourself with the vitality rune. (+2 HP) (%d Uses Left)", vitality);
    }
    printf("\n\n>>> ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 6)
    {
      break;
    }
    else
    {
      continue;
    }
  }

  system("clear");

  switch(choice)
  {
    case 1:
      if (bosscounter == 1)
      {
        hp(2);
        DOT(0, 0, 0);
        battleUI();
        displayUI();
        printf("The king is disappointed by your meager attempt and repeats your attack back onto you, showing how it’s done. (-2 HP)\n\n");
        sleep(5);
        turn++;
        bosscounter = 0;
        goto finalbattle;
      }
      bosscounter = 0;
      DOT(1, 3, 1);
      if (bosshp <= 0)
        goto death;
      battleUI();
      displayUI();
      printf("You activate your Fireball Rune, launching a fiery ball at the king. (+1 Damage per turn!)\n\n");
      sleep(5);
      if (secondskip == 1 || secondskip == 2)
      {
        secondskip -= 1;
        goto finalbattle;
        break;
      }
      turn++;
      goto finalbattle;
      break; 
    case 2:
      if (bosscounter == 1)
      {
        hp(2);
        DOT(0, 0, 0);
        battleUI();
        displayUI();
        printf("The king is disappointed by your meager attempt and repeats your attack back onto you, showing how it’s done. (-2 HP)\n\n");
        sleep(5);
        turn++;
        bosscounter = 0;
        goto finalbattle;
      }
      bosscounter = 0;
      if (bosshp <= 0)
        goto death;
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("You grab the ice rune and activate it, sending an ice path of spikes that pierces the king’s legs and limits his mobility. (Chance to skip the Pallid One's next two turns!)\n\n");
      secondskip = (rand() % 2) + 1;
      sleep(5);
      if (secondskip == 1 || secondskip == 2)
      {
        secondskip -= 1;
        goto finalbattle;
        break;
      }
      turn++;
      goto finalbattle;
      break;
    case 3:
      if (bosscounter == 1)
      {
        hp(2);
        DOT(0, 0, 0);
        battleUI();
        displayUI();
        printf("The king is disappointed by your meager attempt and repeats your attack back onto you, showing how it’s done. (-2 HP)\n\n");
        sleep(5);
        turn++;
        bosscounter = 0;
        goto finalbattle;
      }
      bosscounter = 0;
      bosshp -= 2;
      if (bosshp <= 0)
        goto death;
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("You use your lightning rune to summon two giant bolts of lightning, throwing them at the king like they are spears. (+2 damage)\n\n");
      sleep(5);
      if (secondskip == 1 || secondskip == 2)
      {
        secondskip -= 1;
        goto finalbattle;
        break;
      }
      turn++;
      goto finalbattle;
      break; 
    case 4:
      if (bosshp <= 0)
        goto death;
      DOT(0, 0, 0);
      battleUI();
      displayUI();
      printf("You tense up, ready to parry or dodge against any attack headed your way. (Chance to avoid next two actions!)\n\n");
      avoidchance = (rand() % 2) + 1;
      if (avoidchance == 1)
      {
        dodge = 2;
      }
      sleep(5);
      if (secondskip == 1 || secondskip == 2)
      {
        secondskip -= 1;
        goto finalbattle;
        break;
      }
      turn++;
      goto finalbattle;
      break; 
    case 5:
      if (inventory[3] == 1)
      {
        if (vitality > 0)
        {
          health += 2;
          vitality -= 1;
          if (bosshp <= 0)
            goto death;
          DOT(0, 0, 0);
          battleUI();
          displayUI();
          printf("You hold the rune the knight once had in their chest. Even though you won’t be able to make the same amount of use of it as they did, you feel your stamina being replenished and your wounds closing as you concentrate on the vitality rune. (+2 HP)\n\n");
          sleep(5);
          if (secondskip == 1 || secondskip == 2)
          {
            secondskip -= 1;
            goto finalbattle;
            break;
          }
          turn++;
          goto finalbattle;
          break; 
        }
        else
        {
          system("clear");
          printf("You attempt to concentrate on the vitality rune, but nothing happens.\n\n");
          sleep(5);
          goto attack;
        }
      }
      else
      {
        goto attack;
      }
  }

  pallidAttack: //the boss attacks
  system("clear");
  displayUI();
  chance = (rand() % 7) + 1;
  switch(chance)
  {
    case 1:
      if (dodge > 0)
        dodge -= 1;
      else
        hp(1);
      DOT(0,0,0);
      DOT(0,0,1);
      battleUI();
      displayUI();
      printf("The king swings a volley of slashes around himself like a dangerous whirlwind. You get caught up in the attack and feel the cold crystal make slits in your skin. (-1 HP)\n\n");
      sleep(5);
      turn++;
      goto finalbattle;
      break;
    case 2:
      if (dodge > 0)
        dodge -= 1;
      else
        hp(2);
      DOT(0,0,0);
      DOT(0,0,1);
      battleUI();
      displayUI();
      printf("The king points his pale sword at you before swiftly charging into you in a blink of an eye, piercing your chest. (-2 HP)\n\n");
      sleep(5);
      turn++;
      goto finalbattle;
      break;
    case 3:
      if (dodge > 0)
        dodge -= 1;
      else
        DOT(1, 3, 0);
      DOT(0,0,1);
      battleUI();
      displayUI();
      printf("The king senses the presence of fire in you and rises a wall of flames towards you, engulfing you in a sea of fire. (-1 damage per turn)\n\n");
      sleep(5);
      turn++;
      goto finalbattle;
      break;
    case 4:
      if (dodge > 0)
        dodge -= 1;
      else
        hp(1);
      DOT(0,0,0);
      DOT(0,0,1);
      battleUI();
      displayUI();
      printf("The king senses the presence of frost in you and imbues his sword with a cold mist. He swings his imbued sword at you, causing a path of ice that encases your legs. (-1 HP, Skips next turn)\n\n");
      sleep(5);
      goto finalbattle;
      break;
    case 5:
      if (dodge > 0)
        dodge -= 1;
      else
        hp(3);
      DOT(0,0,0);
      DOT(0,0,1);
      battleUI();
      displayUI();
      printf("The king senses the presence of thunder in you and flashes past you before you can even react, causing massive damage. (-3 HP).\n\n");
      sleep(5);
      turn++;
      goto finalbattle;
      break;
    case 6:
      DOT(0,0,0);
      DOT(0,0,1);
      battleUI();
      displayUI();
      printf("The king taunts you by staying still. He beckons you to attack.\n\n");
      sleep(5);
      bosscounter = 1;
      turn++;
      goto finalbattle;
      break;
    case 7:
      DOT(0,0,0);
      DOT(0,0,1);
      bosshp++;
      battleUI();
      displayUI();
      printf("The king bides his time and gazes at your every move. (King gains +1 HP!)\n\n");
      sleep(5);
      turn++;
      goto finalbattle;
      break;
  }

  death: //the boss death scenarios, good and bad scenarios

  while (1)
  {
    system("clear");
    printf("The king gets brought down to his knees. From your previous attack, his sword had been broken, and his armor was worse for wear. ‘You.. you have bested me. I never thought.. It was possible..’ the Pallid One says as he takes his final breaths. Now that there is nothing to stop you, you peer behind the king’s throne and see a cage that leads up, hopefully to the surface. However, you get a gut feeling that you should check the king’s body.\n\n1. Enter the elevator cage.\n2. Go back to inspect the Pallid One’s body.\n\n>>> ");
    scanf("%d", &choice);
    if (choice == 1)
    {
      system("clear");
      printf("You enter the cage and see its operating system. Once you tinkered with the controls a bit, you got the elevator to start moving up. Soon, you feel the darkness turn to light as sunlight peers over from above, showing you that the elevator does indeed go above ground. You have escaped with your life with the bonus of some sweet runes.\n\n");
      sleep(10);
      credits();
    }
    if (choice == 2)
    {
      system("clear");
      printf("You followed your gut feeling and returned to the Pallid One’s body. While at first glance it seemed normal, you noticed a glint of light coming from his eyes. Just to be careful, you pull out one of your runes and go closer. Yet, you didn’t realize how big of a mistake that was until it was too late. You found out the reason you were there–to be a new host for the parasite that lived in the king. You feel the force controlling the pallid grounds take over your body, and you become just a spectator of your own body.\n\n");
      sleep(10);
      gameOver();
    }
    continue;
  }
}

void credits() //displays credits
{
  system("clear");
  printf("Credits:\n\n");
  sleep(2);
  printf("By the Pixel Paladins\n");
  sleep(2);
  printf("Eddie\n");
  sleep(2);
  printf("Everett\n");
  sleep(2);
  printf("Alex\n");
  sleep(2);
  printf("Thank you to Mrs. Brown\n");
  sleep(2);
  printf("Pallid Ground © 2024\n");
  sleep(2);
  printf("The\n");
  sleep(2);
  printf("End\n");
  sleep(5);
}
