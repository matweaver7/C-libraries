#include <iostream>
#include <sys/types.h>
#include <dirent.h>

using namespace std;

int main() {
    DIR *currentFolder = opendir(".");
    if (currentFolder != NULL) {
        dirent *directory;

        while ((directory = readdir(currentFolder)) != NULL) {
            cout << directory->d_name << endl;
        }
        closedir(currentFolder);
    }
    return 0;
}