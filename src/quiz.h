
#ifndef QUIZ
#define QUIZ
struct user{
    short beginner_friendly;
    bool want_to_configure;
    short release;
    short desktop_experience;
    short desktop_design;
};
enum release{
    stable=1, release
};
enum begginer_friendly{
    yes=1,maybe,no
};
enum out_the_box{
    yes=1,no
};
enum dektop_experience{
    fluid=1,snappy
};
enum desktop_design{
    windows=1,macos,dont_care
};
void quiz(user &user);

#endif