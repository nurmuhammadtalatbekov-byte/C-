#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// ============================================================
// YORDAMCHI FUNKSIYALAR
// ============================================================
void tozala() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void kutish() {
    cout << "\nDavom etish uchun Enter bosing...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void chiziq() {
    cout << string(60, '=') << "\n";
}

void sarlavha(const string& s) {
    tozala();
    chiziq();
    cout << "  " << s << "\n";
    chiziq();
    cout << "\n";
}

// ============================================================
// SAVOL VA JAVOB STRUKTURASI
// ============================================================
struct Savol {
    string savol;
    vector<string> variantlar;
    int togriJavob;
    string izoh;
};

// ============================================================
// DARS STRUKTURASI
// ============================================================
struct Dars {
    string nom;
    string nazariy;
    string misol;
    vector<Savol> test;
};

// ============================================================
// DARSLAR BAZASI
// ============================================================
vector<Dars> darslarYarat() {
    vector<Dars> d;

    // -------- DARS 1 --------
    {
        Dars d1;
        d1.nom = "1-DARS: C++ ga kirish va birinchi dastur";
        d1.nazariy =
            "C++ — bu kuchli, tez va keng tarqalgan dasturlash tili.\n"
            "U 1979-yilda Bjarne Stroustrup tomonidan yaratilgan.\n\n"
            "Har qanday C++ dasturi 'main' funksiyasidan boshlanadi.\n"
            "Kod yozish uchun kerakli narsalar:\n"
            "  1. #include <iostream>  — kiritish/chiqarish kutubxonasi\n"
            "  2. using namespace std;  — standart nomlar maydoni\n"
            "  3. int main() { ... }   — dasturning boshlanish nuqtasi\n\n"
            "Natijani ekranga chiqarish uchun:  cout << \"Salom\";\n"
            "Yangi qatorga o'tish uchun:        endl yoki \\n\n"
            "return 0; — dastur muvaffaqiyatli tugaganini bildiradi.";
        d1.misol =
            "// Birinchi dastur\n"
            "#include <iostream>\n"
            "using namespace std;\n\n"
            "int main() {\n"
            "    cout << \"Salom, dunyo!\" << endl;\n"
            "    return 0;\n"
            "}";

        d1.test = {
            {
                "C++ dasturi qaysi funksiyadan boshlanadi?",
                {"start()", "main()", "begin()", "run()"},
                1,
                "Har qanday C++ dasturi int main() funksiyasidan boshlanadi."
            },
            {
                "Ekranga matn chiqarish uchun nima ishlatiladi?",
                {"cin", "cout", "print", "echo"},
                1,
                "cout — standart chiqish oqimi. cin esa kiritish uchun."
            },
            {
                "Yangi qatorga o'tish uchun nima ishlatiladi?",
                {"endl yoki \\n", "\\t", "\\r", "space"},
                0,
                "endl yoki \\n yangi qatorga o'tadi. \\t — tab."
            }
        };
        d.push_back(d1);
    }

    // -------- DARS 2 --------
    {
        Dars d2;
        d2.nom = "2-DARS: O'zgaruvchilar va ma'lumot turlari";
        d2.nazariy =
            "O'zgaruvchi — bu ma'lumot saqlash uchun nomlangan joy.\n\n"
            "Asosiy ma'lumot turlari:\n"
            "  int     — butun sonlar (masalan: 5, -100)\n"
            "  double  — kasr sonlar (masalan: 3.14)\n"
            "  char    — bitta belgi ('A', 'x')\n"
            "  bool    — mantiqiy qiymat (true / false)\n"
            "  string  — matn (\"Salom\")\n\n"
            "E'lon qilish:\n"
            "  int yosh = 20;\n"
            "  double narx = 9.99;\n"
            "  char harf = 'A';\n"
            "  bool tirik = true;\n"
            "  string ism = \"Ali\";\n\n"
            "O'zgaruvchi nomida bo'sh joy, raqam bilan boshlanishi mumkin emas.\n"
            "Katta-kichik harflar farqli: 'son' va 'Son' — boshqa o'zgaruvchilar.";
        d2.misol =
            "#include <iostream>\n"
            "#include <string>\n"
            "using namespace std;\n\n"
            "int main() {\n"
            "    int yosh = 18;\n"
            "    double boyi = 1.75;\n"
            "    char bahosi = 'A';\n"
            "    bool talaba = true;\n"
            "    string ismi = \"Aziza\";\n\n"
            "    cout << ismi << \" \" << yosh << \" yoshda\" << endl;\n"
            "    cout << \"Bo'yi: \" << boyi << endl;\n"
            "    return 0;\n"
            "}";

        d2.test = {
            {
                "Kasr sonlar uchun qaysi tur ishlatiladi?",
                {"int", "double", "char", "bool"},
                1,
                "double — kasr sonlar uchun. int faqat butun sonlar uchun."
            },
            {
                "Bitta belgi qaysi turda saqlanadi?",
                {"string", "char", "int", "bool"},
                1,
                "char — bitta belgi, masalan 'A'. Bittalik qo'shtirnoq ishlatiladi."
            },
            {
                "Qaysi o'zgaruvchi nomi NOTO'G'RI?",
                {"yosh", "ism1", "1son", "_temp"},
                2,
                "O'zgaruvchi nomi raqam bilan boshlanishi mumkin emas."
            }
        };
        d.push_back(d2);
    }

    // -------- DARS 3 --------
    {
        Dars d3;
        d3.nom = "3-DARS: Kiritish (cin) va arifmetik amallar";
        d3.nazariy =
            "Foydalanuvchidan ma'lumot olish uchun 'cin' ishlatiladi.\n\n"
            "  int son;\n"
            "  cin >> son;\n\n"
            "Arifmetik amallar:\n"
            "  +  qo'shish\n"
            "  -  ayirish\n"
            "  *  ko'paytirish\n"
            "  /  bo'lish  (butun sonlar uchun butun qism olinadi!)\n"
            "  %  qoldiq (faqat butun sonlar uchun)\n\n"
            "Misol: 7 / 2 = 3 (int uchun), lekin 7.0 / 2 = 3.5 (double).";
        d3.misol =
            "#include <iostream>\n"
            "using namespace std;\n\n"
            "int main() {\n"
            "    int a, b;\n"
            "    cout << \"Birinchi sonni kiriting: \";\n"
            "    cin >> a;\n"
            "    cout << \"Ikkinchi sonni kiriting: \";\n"
            "    cin >> b;\n\n"
            "    cout << \"Yig'indi: \" << a + b << endl;\n"
            "    cout << \"Ko'paytma: \" << a * b << endl;\n"
            "    cout << \"Qoldiq: \" << a % b << endl;\n"
            "    return 0;\n"
            "}";

        d3.test = {
            {
                "Foydalanuvchidan ma'lumot olish uchun nima ishlatiladi?",
                {"cout", "cin", "input", "read"},
                1,
                "cin — standart kiritish oqimi. >> operatori bilan ishlatiladi."
            },
            {
                "int uchun 10 / 3 natijasi nechaga teng?",
                {"3.33", "3", "4", "1"},
                1,
                "Butun sonlar bo'linishida kasr qism tashlanadi: 10 / 3 = 3."
            },
            {
                "17 % 5 natijasi nima?",
                {"3", "2", "5", "1"},
                1,
                "% qoldiqni beradi: 17 = 5*3 + 2, qoldiq 2."
            }
        };
        d.push_back(d3);
    }

    // -------- DARS 4 --------
    {
        Dars d4;
        d4.nom = "4-DARS: Shart operatori (if / else)";
        d4.nazariy =
            "Shart operatori kodni faqat ma'lum shart bajarilganda ishga tushiradi.\n\n"
            "  if (shart) {\n"
            "      // rost bo'lsa\n"
            "  } else if (boshqaShart) {\n"
            "      // boshqa shart\n"
            "  } else {\n"
            "      // hech biri bajarilmasa\n"
            "  }\n\n"
            "Taqqoslash: == teng, != teng emas, > katta, < kichik\n"
            "Mantiqiy: && VA, || YOKI, ! EMAS";
        d4.misol =
            "#include <iostream>\n"
            "using namespace std;\n\n"
            "int main() {\n"
            "    int baho;\n"
            "    cout << \"Bahoni kiriting: \";\n"
            "    cin >> baho;\n\n"
            "    if (baho >= 90)       cout << \"A'lo\" << endl;\n"
            "    else if (baho >= 70)  cout << \"Yaxshi\" << endl;\n"
            "    else if (baho >= 50)  cout << \"Qoniqarli\" << endl;\n"
            "    else                  cout << \"Yiqildi\" << endl;\n"
            "    return 0;\n"
            "}";

        d4.test = {
            {
                "Tenglikni tekshirish uchun qaysi operator ishlatiladi?",
                {"=", "==", "!=", "<>"},
                1,
                "== tenglikni tekshiradi. = esa o'zlashtirish operatori."
            },
            {
                "'&&' operatori nimani bildiradi?",
                {"YOKI", "VA", "EMAS", "XOR"},
                1,
                "&& — mantiqiy VA. Ikkala shart ham rost bo'lishi kerak."
            },
            {
                "if (x > 5) — bu kod qachon ishlaydi?",
                {"x 5 ga teng", "x 5 dan katta", "x 5 dan kichik", "har doim"},
                1,
                "x > 5 sharti faqat x 5 dan katta bo'lganda true."
            }
        };
        d.push_back(d4);
    }

    // -------- DARS 5 --------
    {
        Dars d5;
        d5.nom = "5-DARS: Sikllar (for, while, do-while)";
        d5.nazariy =
            "Sikllar kodni bir necha marta takrorlash uchun ishlatiladi.\n\n"
            "1) for — takrorlash soni aniq bo'lganda:\n"
            "   for (int i = 0; i < 5; i++) { ... }\n\n"
            "2) while — shart rost bo'lguncha:\n"
            "   while (shart) { ... }\n\n"
            "3) do-while — kamida bir marta ishlaydi:\n"
            "   do { ... } while (shart);\n\n"
            "break — siklni to'xtatadi, continue — joriy qadamni o'tkazadi.";
        d5.misol =
            "#include <iostream>\n"
            "using namespace std;\n\n"
            "int main() {\n"
            "    for (int i = 1; i <= 5; i++) {\n"
            "        cout << i << \" \";\n"
            "    }\n"
            "    cout << endl;\n\n"
            "    int j = 5;\n"
            "    while (j >= 1) {\n"
            "        cout << j << \" \";\n"
            "        j--;\n"
            "    }\n"
            "    return 0;\n"
            "}";

        d5.test = {
            {
                "for (int i = 0; i < 3; i++) — necha marta ishlaydi?",
                {"2", "3", "4", "cheksiz"},
                1,
                "i = 0, 1, 2 — jami 3 marta."
            },
            {
                "Siklni butunlay to'xtatish uchun nima ishlatiladi?",
                {"continue", "break", "stop", "return"},
                1,
                "break siklni butunlay tark etadi."
            },
            {
                "Qaysi sikl kamida bir marta albatta ishlaydi?",
                {"for", "while", "do-while", "hech qaysi"},
                2,
                "do-while avval bajariladi, keyin shart tekshiriladi."
            }
        };
        d.push_back(d5);
    }

    // -------- DARS 6 --------
    {
        Dars d6;
        d6.nom = "6-DARS: Funksiyalar";
        d6.nazariy =
            "Funksiya — bu nomlangan kod bloki. Kodni qayta ishlatish uchun kerak.\n\n"
            "Struktura:\n"
            "  qaytarishTuri nomi(parametrlar) {\n"
            "      return qiymat;\n"
            "  }\n\n"
            "Turlari:\n"
            "  void     — hech narsa qaytarmaydi\n"
            "  int      — butun son qaytaradi\n"
            "  double   — kasr son\n"
            "  string   — matn";
        d6.misol =
            "#include <iostream>\n"
            "using namespace std;\n\n"
            "int qoshish(int a, int b) {\n"
            "    return a + b;\n"
            "}\n\n"
            "void salom(string ism) {\n"
            "    cout << \"Salom, \" << ism << \"!\" << endl;\n"
            "}\n\n"
            "int main() {\n"
            "    cout << qoshish(3, 5) << endl;\n"
            "    salom(\"Ali\");\n"
            "    return 0;\n"
            "}";

        d6.test = {
            {
                "Funksiya hech narsa qaytarmasa, qaysi tur yoziladi?",
                {"int", "void", "empty", "null"},
                1,
                "void — hech qanday qiymat qaytarmaydi."
            },
            {
                "int kvadrat(int x) { return x * x; }\nkvadrat(4) natijasi?",
                {"8", "16", "4", "xato"},
                1,
                "4 * 4 = 16."
            },
            {
                "Funksiyada qiymat qaytarish uchun qaysi kalit so'z?",
                {"give", "return", "result", "out"},
                1,
                "return — funksiyadan qiymat qaytaradi."
            }
        };
        d.push_back(d6);
    }

    // -------- DARS 7 --------
    {
        Dars d7;
        d7.nom = "7-DARS: Massivlar va vektorlar";
        d7.nazariy =
            "Massiv — bir xil turdagi elementlar to'plami.\n\n"
            "Oddiy massiv:\n"
            "  int sonlar[5] = {10, 20, 30, 40, 50};\n"
            "  cout << sonlar[0]; // 10 (indeks 0 dan boshlanadi)\n\n"
            "Vector (dinamik):\n"
            "  #include <vector>\n"
            "  vector<int> v = {1, 2, 3};\n"
            "  v.push_back(4);\n"
            "  cout << v.size();\n\n"
            "Vector avtomatik kengayadi — bu uning afzalligi.";
        d7.misol =
            "#include <iostream>\n"
            "#include <vector>\n"
            "using namespace std;\n\n"
            "int main() {\n"
            "    vector<int> sonlar = {10, 20, 30};\n"
            "    sonlar.push_back(40);\n\n"
            "    for (int i = 0; i < (int)sonlar.size(); i++) {\n"
            "        cout << sonlar[i] << \" \";\n"
            "    }\n"
            "    return 0;\n"
            "}";

        d7.test = {
            {
                "Massiv indeksi nechadan boshlanadi?",
                {"1", "0", "-1", "ixtiyoriy"},
                1,
                "C++ da massiv indeksi 0 dan boshlanadi."
            },
            {
                "Vektorga element qo'shish uchun qaysi metod?",
                {"add()", "append()", "push_back()", "insert()"},
                2,
                "push_back() — vektor oxiriga element qo'shadi."
            },
            {
                "int a[5] = {1,2,3,4,5}; — a[2] qiymati?",
                {"2", "3", "4", "xato"},
                1,
                "Indeks: a[0]=1, a[1]=2, a[2]=3."
            }
        };
        d.push_back(d7);
    }

    return d;
}

// ============================================================
// TEST O'TKAZISH
// ============================================================
int testOtish(const Dars& d) {
    int togriSoni = 0;
    int jami = (int)d.test.size();

    for (int i = 0; i < jami; i++) {
        sarlavha("TEST — " + d.nom + "  [" + to_string(i + 1) + "/" + to_string(jami) + "]");

        const Savol& s = d.test[i];
        cout << "SAVOL: " << s.savol << "\n\n";

        for (int j = 0; j < (int)s.variantlar.size(); j++) {
            cout << "  " << (char)('A' + j) << ") " << s.variantlar[j] << "\n";
        }

        cout << "\nJavobingiz (A/B/C/D): ";
        string javob;
        cin >> javob;

        int tanlov = -1;
        if (!javob.empty()) {
            char c = toupper(javob[0]);
            if (c >= 'A' && c <= 'D') tanlov = c - 'A';
        }

        cout << "\n";
        if (tanlov == s.togriJavob) {
            cout << "TO'G'RI!\n";
            togriSoni++;
        } else {
            cout << "NOTO'G'RI.\n";
            cout << "To'g'ri javob: "
                 << (char)('A' + s.togriJavob) << ") "
                 << s.variantlar[s.togriJavob] << "\n";
        }
        cout << "Izoh: " << s.izoh << "\n";

        kutish();
    }

    return togriSoni;
}

// ============================================================
// NATIJANI KO'RSATISH
// ============================================================
bool natija(int togri, int jami) {
    sarlavha("TEST NATIJASI");

    double foiz = 100.0 * togri / jami;
    cout << "To'g'ri javoblar: " << togri << " / " << jami << "\n";
    cout << "Foiz: " << (int)foiz << "%\n\n";

    if (foiz >= 80) {
        cout << "Ajoyib! Siz bu mavzuni yaxshi o'zlashtirdingiz!\n";
        return true;
    } else if (foiz >= 60) {
        cout << "Yaxshi, lekin takrorlash foydali bo'ladi.\n";
        return true;
    } else {
        cout << "Mavzuni qayta o'qib chiqing va yana urinib ko'ring.\n";
        return false;
    }
}

// ============================================================
// DARS O'TISH
// ============================================================
void darsOtish(const Dars& d, int raqam, int jami) {
    sarlavha(d.nom + "  [" + to_string(raqam) + "/" + to_string(jami) + "]");
    cout << d.nazariy << "\n\n";
    chiziq();
    cout << "KOD MISOLI:\n";
    chiziq();
    cout << "\n" << d.misol << "\n";
    chiziq();
    kutish();

    int togri = testOtish(d);
    int jamiSavol = (int)d.test.size();
    natija(togri, jamiSavol);
    kutish();
}

// ============================================================
// ASOSIY MENYU
// ============================================================
void menyu(const vector<Dars>& darslar) {
    while (true) {
        sarlavha("C++ O'RGANISH DASTURI");

        cout << "Darslar ro'yxati:\n\n";
        for (int i = 0; i < (int)darslar.size(); i++) {
            cout << "  " << (i + 1) << ". " << darslar[i].nom << "\n";
        }
        cout << "\n";
        chiziq();
        cout << "  0. Chiqish\n";
        cout << "  A. Barcha darslarni ketma-ket o'tish\n";
        chiziq();
        cout << "\nTanlov: ";

        string tanlov;
        cin >> tanlov;

        if (tanlov == "0") {
            cout << "\nXayr! C++ o'rganishda omad tilaymiz!\n";
            return;
        } else if (tanlov == "A" || tanlov == "a") {
            for (int i = 0; i < (int)darslar.size(); i++) {
                darsOtish(darslar[i], i + 1, (int)darslar.size());
            }
        } else {
            try {
                int n = stoi(tanlov);
                if (n >= 1 && n <= (int)darslar.size()) {
                    darsOtish(darslar[n - 1], n, (int)darslar.size());
                } else {
                    cout << "\nBunday dars yo'q.\n";
                    kutish();
                }
            } catch (...) {
                cout << "\nNoto'g'ri tanlov.\n";
                kutish();
            }
        }
    }
}

// ============================================================
// MAIN
// ============================================================
int main() {
    vector<Dars> darslar = darslarYarat();

    sarlavha("XUSH KELIBSIZ!");
    cout << "Bu dastur sizga C++ dasturlash tilini o'zbek tilida o'rgatadi.\n\n";
    cout << "Har bir darsdan keyin test o'tasiz:\n";
    cout << "  - 60% dan yuqori: keyingi darsga o'tish mumkin\n";
    cout << "  - 60% dan past:  darsni qayta o'qish tavsiya etiladi\n\n";
    cout << "Jami darslar soni: " << darslar.size() << "\n";
    kutish();

    menyu(darslar);

    return 0;
}
