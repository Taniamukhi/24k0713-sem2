#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Blend {
public:
    void blend_juice() {
        cout << "Selecting fruits.\n";
        cout << "Blending in progress...\n";
        int i;
        for (i=1; i<=5; i++) 
		{
            cout<< "Blending... " << i << " seconds\n";
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout << "Blending complete.\n";
    }
};

class Grind {
public:
    void grind_juice() {
        cout << "Grinding in progress...\n";
        this_thread::sleep_for(chrono::seconds(5)); 
        cout << "Grinding complete!\n";
    }
};

class Juice_maker {
private:
    Blend blender;
    Grind grinder;
public:
    void blendjuice() { 
        blender.blend_juice(); 
    }

    void grindjuice() { 
        grinder.grind_juice(); 
    }

    void makejuice() {
        cout << "Starting juice preparation...\n";
        blendjuice();
        grindjuice();
        cout << "Juice is ready to serve!\n";
    }
};

int main() 
{
    Juice_maker juicemaker;
    juicemaker.makejuice();
    return 0;
}
