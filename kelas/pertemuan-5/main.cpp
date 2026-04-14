#include <iostream>
using namespace std;
struct mahasiswa
{
    string nama;
    int nim;
};
struct node
{
    mahasiswa mhs;
    node *next;
};
struct node *head = NULL;
struct node *last = NULL;