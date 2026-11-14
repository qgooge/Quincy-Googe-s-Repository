
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Functions
void displaySpellBanner(string spellName, string tier = "Novice", int chargeLevel = 1);
double castSpell(string spellName = "Magic Missile", int basePower = 10, double multiplier = 1.0);
double calculateShield(double baseShield = 15.0, double absorptionRate = 0.20);

int registerCombo(bool hitSuccessful);
void consumeMana(int cost = 5);
bool processBossRage(double damageDealt);
int gainWizardXP(int expGained = 25);

int main()
{
    cout << "=== WIZARD ACADEMY BATTLE SIMULATOR ===\n\n";

    char continueBattle = 'y';
    int turn = 1;

    while (continueBattle == 'y' || continueBattle == 'Y')
    {
        cout << "\n----------------------------------------\n";
        cout << " TURN " << turn << endl;
        cout << "----------------------------------------\n";

        int choice = 0;

        cout << "Select Action:\n";
        cout << "1) Quick Magic Missile (Default attack)\n";
        cout << "2) Heavy Lightning Storm (Custom attack)\n";
        cout << "3) Cast Defensive Barrier\n";
        cout << "4) Miss Attack Intentionally\n";
        cout << "Choice: ";
        cin >> choice;

        double damageDealt = 0.0;
        bool successfulHit = false;

        if (choice == 1)
        {
            displaySpellBanner("Magic Missile");
            damageDealt = castSpell();
            consumeMana();
            successfulHit = true;
        }
        else if (choice == 2)
        {
            displaySpellBanner("Lightning Storm", "Adept", 2);
            damageDealt = castSpell("Lightning Storm", 30, 1.4);
            consumeMana(15);
            successfulHit = true;
        }
        else if (choice == 3)
        {
            displaySpellBanner("Arcane Shield", "Novice", 1);
            double shieldVal = calculateShield(20.0, 0.25);

            cout << "Shield generated! Absorbs "
                 << shieldVal << " incoming damage.\n";

            consumeMana(8);
            successfulHit = true;
        }
        else
        {
            cout << "Your attack missed completely!\n";
            successfulHit = false;
        }

        // Update combo and XP
        int currentCombo = registerCombo(successfulHit);

        if (successfulHit)
        {
            cout << "Current Combo Streak: " << currentCombo << "x\n";
            gainWizardXP(30);
        }

        // Check boss damage
        bool isBossEnraged = processBossRage(damageDealt);

        if (isBossEnraged)
        {
            cout << "!!! WARNING: BOSS HAS ENTERED ENRAGE MODE !!!\n";
        }

        turn++;

        cout << "\nEnd turn? Continue fighting? (y/n): ";
        cin >> continueBattle;
    }

    cout << "\n=== BATTLE SIMULATION ENDED ===\n";

    return 0;
}

// Displays the spell banner
void displaySpellBanner(string spellName, string tier, int chargeLevel)
{
    cout << "\nSpell Cast: " << spellName << endl;
    cout << "Tier: " << tier << endl;
    cout << "Charge Level: " << chargeLevel << endl;
}

// Calculates spell damage
double castSpell(string spellName, int basePower, double multiplier)
{
    double damage = basePower * multiplier;

    cout << "\nAttack: " << spellName << endl;
    cout << "Damage: " << damage << " HP\n";

    return damage;
}

// Calculates shield protection
double calculateShield(double baseShield, double absorptionRate)
{
    double wardValue = baseShield * (1 + absorptionRate);

    return wardValue;
}

// Tracks the current combo
int registerCombo(bool hitSuccessful)
{
    static int comboCount = 0;

    if (hitSuccessful)
    {
        comboCount++;
    }
    else
    {
        comboCount = 0;
        cout << "Combo lost! Your streak has reset.\n";
    }

    return comboCount;
}

// Tracks total mana used
void consumeMana(int cost)
{
    static int totalManaUsed = 0;

    totalManaUsed += cost;

    cout << "Total Mana Used: " << totalManaUsed << endl;
}

// Tracks total damage dealt to the boss
bool processBossRage(double damageDealt)
{
    static double totalDamageDealt = 0.0;

    totalDamageDealt += damageDealt;

    return totalDamageDealt >= 100.0;
}

// Tracks wizard XP and level
int gainWizardXP(int expGained)
{
    static int totalXP = 0;
    static int wizardLevel = 1;

    totalXP += expGained;

    cout << "Total Wizard XP: " << totalXP << endl;

    if (totalXP >= wizardLevel * 100)
    {
        wizardLevel++;
        cout << "LEVEL UP! You are now level " << wizardLevel << "!\n";
    }

    return wizardLevel;
}
