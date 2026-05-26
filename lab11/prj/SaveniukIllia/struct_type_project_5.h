#ifndef STRUCT_TYPE_PROJECT_5_H
#define STRUCT_TYPE_PROJECT_5_H

// Структура, содержащая все 18 полей Варианта 5
struct EducationalEntity {
    int edeboCode;                         // 1. Код закладу в ЄДЕБО
    char fullName[256];                    // 2. Повне найменування
    char shortName[100];                   // 3. Коротка назва
    char englishName[256];                 // 4. Повне найменування (англ.)
    char ownershipForm[100];               // 5. Форма власності
    char governingBody[256];               // 6. Найменування органу до сфери управління
    char managerPosition[150];             // 7. Найменування посади керівника
    char managerLastName[100];             // 8. Прізвище керівника
    char managerFirstName[100];            // 9. Ім'я керівника
    char managerPatronymic[100];           // 10. По батькові керівника
    char address[256];                     // 11. Місцезнаходження (юридична адреса)
    char phone[50];                        // 12. Телефон / факс
    char email[150];                       // 13. Електронна пошта
    char website[150];                     // 14. Веб-сайт
    char isCrimeaCenter[20];               // 15. ОЦ «Крим-Україна» (так/ні)
    char isDonbasCenter[20];               // 16. ОЦ «Донбас-Україна» (так/ні)
    char hasMilitaryDepartment[20];        // 17. Військова кафедра (так/ні)
    int establishmentYear;                 // 18. Рік заснування
};

// Узел односвязного списка
struct Node {
    EducationalEntity data;
    Node* next;
};

#endif // STRUCT_TYPE_PROJECT_5_H
