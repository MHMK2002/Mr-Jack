
enum ORDER{beforeOrAfter, afterMovement, movementOrFunctionality, simultaneous};
struct SergentGoodley
{
    char name[3];
    char nameForPrint[17];
    bool visible;
    int maximumOfMovement;
    short order;
}SG;

struct SherlockHolmes
{
    char name[3];
    char nameForPrint[25];
    bool visible;
    int maximumOfMovement;
    short order;
}SH;

struct JohnWatson
{
    char name[3];
    char nameForPrint[17];
    bool visible;
    int maximumOfMovement;
    short order;
}JW;

struct JeremyBert
{
    char name[3];
    char nameForPrint[17];
    bool visible;
    int maximumOfMovement;
    short order;
}JB;

struct MissStealthy
{
char name[3];
    char nameForPrint[17];
    bool visible;
    int maximumOfMovement;
    short order;
}MS;

struct InspectorLestrade
{
    char name[3];
    char nameForPrint[17];
    bool visible;
    int maximumOfMovement;
    short order;
}IL;

struct SirWilliamGull
{
    char name[3];
    char nameForPrint[17];
    bool visible;
    int maximumOfMovement;
    short order;
}SW;

struct JohnSmith
{
    char name[3];
    char nameForPrint[17];
    bool visible;
    int maximumOfMovement;
    short order;
}JS;

struct Character SergentGoodley = {"SG", "\033[0;34mS\033[0;31mG\033[0;38m", false, 4, beforeOrAfter};
struct Character SherlockHolmes = {"SH", "\033[0;31mSH\033[0;38m", false, 3, afterMovement};
struct Character JohnWatson = {"JW", "\033[0;33mJW\033[0;38m", false, 3, afterMovement};
struct Character JeremyBert = {"JB", "\033[0;36mJB\033[0;38m", false, 3, beforeOrAfter};
struct Character MissStealthy = {"MS", "\033[0;32mMS\033[0;38m", false, 3, simultaneous};
struct Character InspectorLestrade = {"", "\033[0;34mIN\033[0;38m", false, 3, beforeOrAfter};
struct Character SirWilliamGull = {"SG", "\033[0;35mSW\033[0;38m", false, 3, movementOrFunctionality};
struct Character JohnSmith = {"SG", "\033[0;33mJS\033[0;38m", false, 3, beforeOrAfter};


