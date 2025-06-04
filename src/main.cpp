#include <iostream>
#include "MyContainer.hpp"

int main() {
    try {
        // יצירת קונטיינר של מספרים שלמים
        MyContainer<int> mc;

        // הוספת איברים
        mc.add(7);
        mc.add(15);
        mc.add(6);
        mc.add(1);
        mc.add(2);

        std::cout << "Original container: " << mc << std::endl;
        std::cout << "Size: " << mc.size() << std::endl;

        // הדפסה לפי סדר עולה
        std::cout << "Ascending order: ";
        MyContainer<int>::AscendingOrder asc(mc);
        for (auto val : asc) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        // הדפסה לפי סדר יורד
        std::cout << "Descending order: ";
        MyContainer<int>::DescendingOrder desc(mc);
        for (auto val : desc) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        //sideCross
        std::cout << "SideCrossOrder order: ";
        MyContainer<int>::SideCrossOrder side(mc);
        for (auto val : side) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        // הדפסה לפי ReverseOrder
        std::cout << "Reverse order: ";
        MyContainer<int>::ReverseOrder rev(mc);
        for (auto val : rev) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        

        // ניסיון למחוק איבר קיים
        mc.remove(6);
        std::cout << "After removing 6: " << mc << std::endl;

        // ניסיון למחוק איבר שלא קיים
        std::cout << "Trying to remove 99 (not in container):" << std::endl;
        mc.remove(99);  // אמור לזרוק שגיאה

    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
