#include "unity.h"
#include <stdbool.h>
#include <stdlib.h>
#include "../../examples/autotest-validate/autotest-validate.h"
#include "../../assignment-autotest/test/assignment1/username-from-conf-file.h" //This is the header file

/**
* This function should:
*   1) Call the my_username() function in autotest-validate.c to get your hard coded username.
*   2) Obtain the value returned from function malloc_username_from_conf_file() in username-from-conf-file.h within
*       the assignment autotest submodule at assignment-autotest/test/assignment1/
*   3) Use unity assertion TEST_ASSERT_EQUAL_STRING_MESSAGE to verify the two strings are equal.  See
*       the [unity assertion reference](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)
*/

// Declaration of my_username() function
const char* my_username();

// Declaration of setUp() function
void setUp() {
}

// Declaration of tearDown() function
void tearDown() {
}

/** I'm rusty on C coding and was curious if I could get this to work with running Unity locally
 *      - The command to get this to run was nasty and I couldn't figure out a way to not copy the
 *      headers and source files to my working directory
 *      - I did manage to get this to work compiling with gcc from command line and linking to the 
 *      complete path to the autotestvalidate and the conf file
 *      - I deleted the duplicate unity headers and source in my working directory when pushing to
 *      git. It would still work with an updated command to link to the unity src (I think?).
 *  */ 

void test_validate_my_username(){
    
    // Call my_username() function
    const char* username1 = my_username();
    printf("Username from my_username(): %s\n", username1);

    // Obtain the value from the conf file
    char* username2 = malloc_username_from_conf_file();
    printf("Username from malloc_username_from_conf_file(): %s\n", username2);

    // Using the Unity assertion 
    TEST_ASSERT_EQUAL_STRING_MESSAGE(username1, username2, "Usernames are not equal");

    free(username2);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_validate_my_username);
    return UNITY_END();
}

/** void test_validate_my_username()
{
    
     * TODO: Replace the line below with your code here as described above to verify your /conf/username.txt 
     * config file and my_username() functions are setup properly
     
    
    //TEST_ASSERT_TRUE_MESSAGE(false,"AESD students, please fix me!");
    printf("Username: %s\n", my_username());
}
*/