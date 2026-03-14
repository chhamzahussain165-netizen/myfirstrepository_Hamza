 #include <iostream>
using namespace std;

// Forward declarations to resolve circular dependencies if any, though not strictly needed here
// since classes are fully defined before use in main.
class ParahInfo;
class SurahInfo;
class ManzilInfo;

class QuranSystem {
public:
    void intro() {
    
        cout << "Assalam-o-Alaikum" << endl;
        cout << "Welcome to the Quran Management System" << endl;
        cout << "Here You Will Get Information About the Quran:" << endl;
        cout << "1 - Parah" << endl;
        cout << "2 - Surahs And Verses" << endl;
        cout << "3 - Manzils" << endl;
        cout << "4 - Exit" << endl;
    }
};

class ParahInfo {
public:
    void displayParah(int parah) {
        switch (parah) {
            case 1:
                cout << "Parah 1: Alif Lam Meem\n";
                cout << "Theme: The Oneness of Allah, and the concept of guidance and belief.\n";
                cout << "Surahs: Surah Al-Fatiha (1:1–7), Surah Al-Baqarah (2:1–141)\n";
                break;
            case 2:
                cout << "Parah 2: Sayaqool\n";
                cout << "Theme: Belief in the unseen, faith in Allah's plan, and the role of prophets.\n";
                cout << "Surahs: Surah Al-Baqarah (2:142–252)\n";
                break;
            case 3:
                cout << "Parah 3: Tilkal Rusul\n";
                cout << "Theme: The stories of past nations, the consequences of their actions, and the importance of belief in prophets.\n";
                cout << "Surahs: Surah Al-Baqarah (2:253–286), Surah Aal-E-Imran (3:1–92)\n";
                break;
            case 4:
                cout << "Parah 4: Lan Tana Loo\n";
                cout << "Theme: Charity, righteousness, and the need for justice in society.\n";
                cout << "Surahs: Surah Aal-E-Imran (3:93–200), Surah An-Nisa (4:1–23)\n";
                break;
            case 5:
                cout << "Parah 5: Wal Mohsanat\n";
                cout << "Theme: The concept of justice, prohibition of certain acts, and dealing with social issues.\n";
                cout << "Surahs: Surah An-Nisa (4:24–147)\n";
                break;
            case 6:
                cout << "Parah 6: La Yuhibbullah\n";
                cout << "Theme: The importance of belief in Allah’s decrees and the consequences of disbelief.\n";
                cout << "Surahs: Surah An-Nisa (4:148–176), Surah Al-Ma'idah (5:1–81)\n";
                break;
            case 7:
                cout << "Parah 7: Wa Iza Samiu\n";
                cout << "Theme: Laws of family life, ethics, and the consequences of hypocrisy.\n";
                cout << "Surahs: Surah Al-Ma'idah (5:82–120), Surah Al-An'am (6:1–110)\n";
                break;
            case 8:
                cout << "Parah 8: Wa Lau Annana\n";
                cout << "Theme: The importance of faith in times of adversity and the lessons from past communities.\n";
                cout << "Surahs: Surah Al-An'am (6:111–165), Surah Al-A'raf (7:1–87)\n";
                break;
            case 9:
                cout << "Parah 9: Qad Aflaha\n";
                cout << "Theme: Striving for good deeds, making sacrifices, and the consequences of sin.\n";
                cout << "Surahs: Surah Al-A'raf (7:88–206), Surah Al-Anfal (8:1–40)\n";
                break;
            case 10:
                cout << "Parah 10: Wa A'lamu\n";
                cout << "Theme: The importance of unity, obedience to Allah, and the guidance of the Prophet.\n";
                cout << "Surahs: Surah Al-Anfal (8:41–75), Surah At-Tawbah (9:1–93)\n";
                break;
            case 11:
                cout << "Parah 11: Yatazeroon\n";
                cout << "Theme: Accountability in the Hereafter, the Day of Judgment, and the consequences of actions.\n";
                cout << "Surahs: Surah At-Tawbah (9:94–129), Surah Yunus (10:1–109)\n";
                break;
            case 12:
                cout << "Parah 12: Wa Mamin Dabbah\n";
                cout << "Theme: The stories of previous nations, their rejection of messengers, and their downfall.\n";
                cout << "Surahs: Surah Hud (11:1–123)\n";
                break;
            case 13:
                cout << "Parah 13: Wa Ma Ubrioo\n";
                cout << "Theme: The stories of Yusuf and the message of patience and perseverance in faith.\n";
                cout << "Surahs: Surah Yusuf (12:1–111), Surah Ar-Ra'd (13:1–43)\n";
                break;
            case 14:
                cout << "Parah 14: Rubama\n";
                cout << "Theme: Reflection on the power of Allah, the importance of gratitude, and warnings to the disbelievers.\n";
                cout << "Surahs: Surah Ibrahim (14:1–52), Surah Al-Hijr (15:1–99)\n";
                break;
            case 15:
                cout << "Parah 15: Subhanallazi\n";
                cout << "Theme: The concept of divine revelation, guidance, and the choice between belief and disbelief.\n";
                cout << "Surahs: Surah An-Nahl (16:1–128)\n";
                break;
                case 16:
                cout << "Parah 16: Qal Alam\n";
                cout << "Theme: Reflections on creation and the signs of Allah, and the consequences of rejecting faith.\n";
                cout << "Surahs: Surah Al-Isra (17:1–111), Surah Al-Kahf (18:1–74)\n";
                break;
            case 17:
                cout << "Parah 17: Aqtarabat\n";
                cout << "Theme: The approaching Hour, descriptions of the Hereafter, and a reminder of the purpose of life.\n";
                cout << "Surahs: Surah Al-Kahf (18:75–110), Surah Maryam (19:1–98), Surah Ta-Ha (20:1–135)\n";
                break;
            case 18:
                cout << "Parah 18: Qadd Aflaha\n";
                cout << "Theme: Stories of the Prophets and their communities, focusing on those who succeeded and those who failed.\n";
                cout << "Surahs: Surah Al-Anbiya (21:1–112), Surah Al-Hajj (22:1–78)\n";
                break;
            case 19:
                cout << "Parah 19: Wa Qalallazina\n";
                cout << "Theme: The importance of faith and the consequences of disbelief, with the focus on the people of the past.\n";
                cout << "Surahs: Surah Al-Mu'minun (23:1–118), Surah An-Nur (24:1–64), Surah Al-Furqan (25:1–20)\n";
                break;
            case 20:
                cout << "Parah 20: Amman Khalaq\n";
                cout << "Theme: Divine creation, signs of Allah, and the Day of Judgment.\n";
                cout << "Surahs: Surah Al-Furqan (25:21–77), Surah Ash-Shu'ara (26:1–227), Surah An-Naml (27:1–55)\n";
                break;
            case 21:
                cout << "Parah 21: Utlu Ma Oohi\n";
                cout << "Theme: The mission of the Prophet and the continuation of divine messages through previous nations.\n";
                cout << "Surahs: Surah An-Naml (27:56–93), Surah Al-Qasas (28:1–88), Surah Al-Ankabut (29:1–45)\n";
                break;
            case 22:
                cout << "Parah 22: Wa Manyaqnut\n";
                cout << "Theme: Divine sovereignty, the proof of the Hereafter, and the contrast between believers and disbelievers.\n";
                cout << "Surahs: Surah Al-Ankabut (29:46–69), Surah Ar-Rum (30:1–60), Surah Luqman (31:1–34), Surah As-Sajdah (32:1–30)\n";
                break;
            case 23:
                cout << "Parah 23: Wa Mali\n";
                cout << "Theme: The trials of believers, the importance of patience, and lessons from past communities.\n";
                cout << "Surahs: Surah Al-Ahzab (33:1–73), Surah Saba (34:1–54), Surah Fatir (35:1–45)\n";
                break;
            case 24:
                cout << "Parah 24: Faman Azlam\n";
                cout << "Theme: Reflections on the Day of Judgment, the fate of the disbelievers, and the rewards for the righteous.\n";
                cout << "Surahs: Surah Yasin (36:1–83), Surah As-Saffat (37:1–182), Surah Sad (38:1–88)\n";
                break;
            case 25:
                cout << "Parah 25: Elahe Yuruddu\n";
                cout << "Theme: Reflections on creation, signs of Allah, and the warnings to those who reject belief.\n";
                cout << "Surahs: Surah Az-Zumar (39:1–75), Surah Ghafir (40:1–85)\n";
                break;
            case 26:
                cout << "Parah 26: Ha Meem\n";
                cout << "Theme: Divine signs, guidance, and the ultimate fate of the disbelievers.\n";
                cout << "Surahs: Surah Fussilat (41:1–54), Surah Ash-Shura (42:1–53), Surah Az-Zukhruf (43:1–89)\n";
                break;
            case 27:
                cout << "Parah 27: Qala Fama Khatbukum\n";
                cout << "Theme: Divine justice, the fate of the disbelievers, and the lessons from history.\n";
                cout << "Surahs: Surah Ad-Dukhan (44:1–59), Surah Al-Jathiyah (45:1–37), Surah Al-Ahqaf (46:1–35)\n";
                break;
            case 28:
                cout << "Parah 28: Qadd Aflaha\n";
                cout << "Theme: Belief in the unseen and the reality of the Hereafter.\n";
                cout << "Surahs: Surah Muhammad (47:1–38), Surah Al-Fath (48:1–29), Surah Al-Hujurat (49:1–18), Surah Qaf (50:1–45), Surah Adh-Dhariyat (51:1–30)\n";
                break;
            case 29:
                cout << "Parah 29: Tabarakallazi\n";
                cout << "Theme: Reflection on divine sovereignty and the certainty of the Day of Judgment.\n";
                cout << "Surahs: Surah Al-Mulk (67:1–30), Surah Al-Qalam (68:1–52), Surah Al-Haqqah (69:1–52), Surah Al-Ma'arij (70:1–44), Surah Nuh (71:1–28), Surah Al-Jinn (72:1–28), Surah Al-Muzzammil (73:1–20), Surah Al-Muddathir (74:1–56), Surah Al-Qiyamah (75:1–40), Surah Al-Insan (76:1–31), Surah Al-Mursalat (77:1–50)\n";
                break;
            case 30:
                cout << "Parah 30: Amma Yatasa'aloon\n";
                cout << "Theme: The fundamental beliefs of Islam—Tawhid (Oneness of Allah), the Hereafter, and accountability.\n";
                cout << "Surahs: Surah An-Naba (78:1–40), Surah An-Nazi'at (79:1–46), Surah Abasa (80:1–42), Surah At-Takwir (81:1–29), Surah Al-Infitar (82:1–19), Surah Al-Mutaffifin (83:1–36), Surah Al-Inshiqaq (84:1–25), Surah Al-Buruj (85:1–22), Surah At-Tariq (86:1–17), Surah Al-A'la (87:1–19), Surah Al-Ghashiyah (88:1–26), Surah Al-Fajr (89:1–30), Surah Al-Balad (90:1–20), Surah Ash-Shams (91:1–15), Surah Al-Lail (92:1–21), Surah Ad-Duhaa (93:1–11), Surah Ash-Sharh (94:1–8), Surah At-Tin (95:1–8), Surah Al-'Alaq (96:1–19), Surah Al-Qadr (97:1–5), Surah Al-Bayyina (98:1–8), Surah Az-Zalzalah (99:1–8), Surah Al-Adiyat (100:1–11), Surah Al-Qari'ah (101:1–11), Surah At-Takathur (102:1–8), Surah Al-Asr (103:1–3), Surah Al-Humazah (104:1–9), Surah Al-Fil (105:1–5), Surah Quraish (106:1–4), Surah Al-Ma'un (107:1–7), Surah Al-Kawthar (108:1–3), Surah Al-Kafiroon (109:1–6), Surah An-Nasr (110:1–3), Surah Al-Masad (111:1–5), Surah Al-Ikhlas (112:1–4), Surah Al-Falaq (113:1–5), Surah An-Nas (114:1–6)\n";
                break;
            default:
                cout << "Invalid input. Please enter a number between 1 and 30.\n";
                break;
        }
    }
};

class SurahInfo {
public:
    void displaySurah(int num) {
        switch(num) {
            case 1:
                cout << "Al-Fatihah\nVerses: 7\nAllah introduces Himself, guides humans to the straight path, and praises Himself as the Lord of the universe.\n";
                break;
            case 2:
                cout << "Al-Baqarah\nVerses: 286\nAllah explains faith, prayer, charity, and warns against hypocrisy.\n";
                break;
            case 3:
                cout << "Al-Imran\nVerses: 200\nAllah tells the story of Prophet Ibrahim and his family, emphasizing faith and obedience.\n";
                break;
            case 4:
                cout << "An-Nisa\nVerses: 176\nAllah discusses marriage, divorce, inheritance, and emphasizes justice and fairness.\n";
                break;
            case 5:
                cout << "Al-Ma'idah\nVerses: 120\nAllah explains prayer, charity, fasting, and warns against corruption.\n";
                break;
            case 6:
                cout << "Al-An'am\nVerses: 165\nAllah explains Tawhid (oneness of God) and warns against polytheism.\n";
                break;
            case 7:
                cout << "Al-A'raf\nVerses: 206\nAllah tells the story of Prophet Musa and the Children of Israel.\n";
                break;
            case 8:
                cout << "Al-Anfal\nVerses: 75\nFocuses on the Battle of Badr and its lessons.\n";
                break;
            case 9:
                cout << "At-Tawbah\nVerses: 129\nDiscusses repentance, hypocrisy, and preparation for battles.\n";
                break;
            case 10:
                cout << "Yunus\nVerses: 109\nNamed after Prophet Yunus (Jonah); highlights Allah's mercy.\n";
                break;
            case 11:
                cout << "Hud\nVerses: 123\nFocuses on the stories of past prophets, including Hud.\n";
                break;
            case 12:
                cout << "Yusuf\nVerses: 111\nDetails the life story of Prophet Yusuf (Joseph).\n";
                break;
            case 13:
                cout << "Ar-Ra'd\nVerses: 43\nMentions the signs of Allah's power in creation.\n";
                break;
            case 14:
                cout << "Ibrahim\nVerses: 52\nNamed after Prophet Ibrahim (Abraham); emphasizes gratitude.\n";
                break;
            case 15:
                cout << "Al-Hijr\nVerses: 99\nDiscusses the destruction of past nations.\n";
                break;
            case 16:
                cout << "An-Nahl\nVerses: 128\nHighlights Allah's blessings and signs in nature.\n";
                break;
            case 17:
                cout << "Al-Isra\nVerses: 111\nFocuses on the journey of Isra and Mi'raj of the Prophet Muhammad (PBUH).\n";
                break;
            case 18:
                cout << "Al-Kahf\nVerses: 110\nContains the story of the People of the Cave and Dhul-Qarnayn.\n";
                break;
            case 19:
                cout << "Maryam\nVerses: 98\nNamed after Mary (Maryam), the mother of Prophet Isa (Jesus).\n";
                break;
            case 20:
                cout << "Ta-Ha\nVerses: 135\nFocuses on the story of Prophet Musa (Moses).\n";
                break;
            case 21:
                cout << "Al-Anbiya\nVerses: 112\nMentions several prophets and their struggles.\n";
                break;
            case 22:
                cout << "Al-Hajj\nVerses: 78\nDiscusses the pilgrimage (Hajj) and sacrifice.\n";
                break;
            case 23:
                cout << "Al-Mu'minun\nVerses: 118\nDescribes the qualities of true believers.\n";
                break;
            case 24:
                cout << "An-Nur\nVerses: 64\nContains the famous verse of light (Ayat an-Nur).\n";
                break;
            case 25:
                cout << "Al-Furqan\nVerses: 77\nEmphasizes the criterion between right and wrong.\n";
                break;
            case 26:
                cout << "Ash-Shu'ara\nVerses: 227\nFocuses on the struggles of past prophets.\n";
                break;
            case 27:
                cout << "An-Naml\nVerses: 93\nMentions the story of Prophet Sulaiman (Solomon) and the ants.\n";
                break;
            case 28:
                cout << "Al-Qasas\nVerses: 88\nRelates the story of Prophet Musa (Moses) and Pharaoh.\n";
                break;
            case 29:
                cout << "Al-Ankabut\nVerses: 69\nUses the spider as a metaphor for weakness.\n";
                break;
            case 30:
                cout << "Ar-Rum\nVerses: 60\nDiscusses the rise and fall of nations.\n";
                break;
            case 31:
                cout << "Luqman\nVerses: 34\nHighlights the wisdom of Luqman.\n";
                break;
            case 32:
                cout << "As-Sajda\nVerses: 30\nEncourages prostration and belief in resurrection.\n";
                break;
            case 33:
                cout << "Al-Ahzab\nVerses: 73\nDiscusses the Battle of the Confederates.\n";
                break;
            case 34:
                cout << "Saba\nVerses: 54\nHighlights the blessings of Allah to the people of Saba.\n";
                break;
            case 35:
                cout << "Fatir\nVerses: 45\nPraises Allah's creation and power.\n";
                break;
            case 36:
                cout << "Ya-Sin\nVerses: 83\nKnown as the heart of the Quran.\n";
                break;
            case 37:
                cout << "As-Saffat\nVerses: 182\nMentions the ranks of angels and the story of Ibrahim's sacrifice.\n";
                break;
            case 38:
                cout << "Sad\nVerses: 88\nMentions the story of Prophet Dawood (David).\n";
                break;
            case 39:
                cout << "Az-Zumar\nVerses: 75\nEmphasizes sincerity in worship.\n";
                break;
            case 40:
                cout << "Ghafir\nVerses: 85\nFocuses on forgiveness and warnings for disbelievers.\n";
                break;
            case 41:
                cout << "Fussilat\nVerses: 54\nDescribes the signs of Allah in the universe.\n";
                break;
            case 42:
                cout << "Ash-Shura\nVerses: 53\nEncourages mutual consultation among believers.\n";
                break;
            case 43:
                cout << "Az-Zukhruf\nVerses: 89\nWarns against materialism.\n";
                break;
            case 44:
                cout << "Ad-Dukhan\nVerses: 59\nDiscusses the smoke as a sign of the Day of Judgment.\n";
                break;
            case 45:
                cout << "Al-Jathiya\nVerses: 37\nDescribes the fate of the arrogant.\n";
                break;
            case 46:
                cout << "Al-Ahqaf\nVerses: 35\nMentions the punishment of the people of 'Ad.\n";
                break;
            case 47:
                cout << "Muhammad\nVerses: 38\nDiscusses the characteristics of believers and disbelievers.\n";
                break;
            case 48:
                cout << "Al-Fath\nVerses: 29\nNamed after the Treaty of Hudaybiyyah.\n";
                break;
            case 49:
                cout << "Al-Hujurat\nVerses: 18\nTeaches manners and social ethics.\n";
                break;
            case 50:
                cout << "Qaf\nVerses: 45\nEmphasizes the reality of resurrection.\n";
                break;
            case 51:
                cout << "Adh-Dhariyat\nVerses: 60\nEncourages reflecting on Allah's signs in creation.\n";
                break;
            case 52:
                cout << "At-Tur\nVerses: 49\nDescribes scenes of the Day of Judgment.\n";
                break;
            case 53:
                cout << "An-Najm\nVerses: 62\nFocuses on the ascension (Mi'raj) of the Prophet Muhammad (PBUH).\n";
                break;
            case 54:
                cout << "Al-Qamar\nVerses: 55\nMentions the splitting of the moon as a miracle.\n";
                break;
            case 55:
                cout << "Ar-Rahman\nVerses: 78\nKnown as the surah of mercy; repeats 'Which of your Lord's favors will you deny?'\n";
                break;
            case 56:
                cout << "Al-Waqia\nVerses: 96\nDescribes the events of the Day of Judgment.\n";
                break;
            case 57:
                cout << "Al-Hadid\nVerses: 29\nDiscusses Allah's power and the importance of charity.\n";
                break;
            case 58:
                cout << "Al-Mujadila\nVerses: 22\nMentions the rulings on disputes and oaths.\n";
                break;
            case 59:
                cout << "Al-Hashr\nVerses: 24\nContains Allah's beautiful names (Asma'ul Husna).\n";
                break;
            case 60:
                cout << "Al-Mumtahanah\nVerses: 13\nAllah guides believers on dealing with non-believers and emphasizes loyalty to the faith.\n";
                break;
            case 61:
                cout << "As-Saff\nVerses: 14\nAllah emphasizes unity in the faith and the importance of striving for His cause.\n";
                break;
            case 62:
                cout << "Al-Jumu'ah\nVerses: 11\nAllah explains the importance of the Friday prayer and the significance of following the Prophet’s example.\n";
                break;
            case 63:
                cout << "Al-Munafiqun\nVerses: 11\nAllah warns against hypocrisy and emphasizes sincerity in faith.\n";
                break;
            case 64:
                cout << "At-Taghabun\nVerses: 18\nAllah speaks about the consequences of disbelief and the reward for those who believe and act righteously.\n";
                break;
            case 65:
                cout << "At-Talaq\nVerses: 12\nAllah gives guidance regarding divorce, family matters, and the proper treatment of women.\n";
                break;
            case 66:
                cout << "At-Tahrim\nVerses: 12\nAllah discusses issues of personal conduct, especially regarding relationships and following the Prophet’s guidance.\n";
                break;
            case 67:
                cout << "Al-Mulk\nVerses: 30\nAllah emphasizes His sovereignty over creation and reminds humanity of their accountability on the Day of Judgment.\n";
                break;
            case 68:
                cout << "Al-Qalam\nVerses: 52\nAllah encourages patience and perseverance in the face of adversity and rejection.\n";
                break;
            case 69:
                cout << "Al-Haqqah\nVerses: 52\nAllah describes the certainty of the Day of Judgment and the consequences for the disbelievers.\n";
                break;
            case 70:
                cout << "Al-Ma'arij\nVerses: 44\nAllah speaks about the characteristics of the disbelievers and the rewards for the righteous.\n";
                break;
             case 71:
                cout << "Nuh\nVerses: 28\nAllah narrates the story of Prophet Nuh and his people, and how they were destroyed for their disobedience.\n";
                break;
            case 72:
                cout << "Al-Jinn\nVerses: 28\nAllah speaks about the existence of jinn, their behavior, and their response to the message of Islam.\n";
                break;
            case 73:
                cout << "Al-Muzzammil\nVerses: 20\nAllah instructs the Prophet to pray in the night and explains the importance of devotion.\n";
                break;
            case 74:
                cout << "Al-Muddathir\nVerses: 56\nAllah calls on the Prophet to rise up and warn humanity of the impending punishment for the disbelievers.\n";
                break;
            case 75:
                cout << "Al-Qiyamah\nVerses: 40\nAllah speaks about the certainty of the Day of Resurrection and the fate of the disbelievers.\n";
                break;
            case 76:
                cout << "Al-Insan\nVerses: 31\nAllah speaks about the creation of humans, their trials in life, and the reward for the righteous.\n";
                break;
            case 77:
                cout << "Al-Mursalat\nVerses: 50\nAllah describes the Day of Judgment and the fate of those who reject the truth.\n";
                break;
            case 78:
                cout << "An-Naba\nVerses: 40\nAllah describes the signs of the Day of Judgment and the fate of the righteous and the wicked.\n";
                break;
            case 79:
                cout << "An-Nazi'at\nVerses: 46\nAllah speaks about the resurrection and the fate of those who deny it.\n";
                break;
            case 80:
                cout << "Abasa\nVerses: 42\nAllah reprimands the Prophet for turning away from a blind man and emphasizes the importance of compassion.\n";
                break;
            case 81:
                cout << "At-Takwir\nVerses: 29\nAllah describes the cosmic events that will occur during the Day of Judgment.\n";
                break;
            case 82:
                cout << "Al-Infitar\nVerses: 19\nAllah speaks about the end of the world and the consequences of human deeds.\n";
                break;
            case 83:
                cout << "Al-Mutaffifin\nVerses: 36\nAllah condemns those who cheat others in business and emphasizes the consequences for them.\n";
                break;
            case 84:
                cout << "Al-Inshiqaq\nVerses: 25\nAllah describes the upheaval of the universe on the Day of Judgment.\n";
                break;
            case 85:
                cout << "Al-Buruj\nVerses: 22\nAllah speaks about the punishment for those who persecuted the believers and the reward for the righteous.\n";
                break;
            case 86:
                cout << "At-Tariq\nVerses: 17\nAllah speaks about the creation of humans and the certainty of the Day of Judgment.\n";
                break;
            case 87:
                cout << "Al-A'la\nVerses: 19\nAllah calls on humans to glorify and praise Him, and reminds them of the signs of His creation.\n";
                break;
            case 88:
                cout << "Al-Ghashiyah\nVerses: 26\nAllah describes the condition of the disbelievers on the Day of Judgment.\n";
                break;
            case 89:
                cout << "Al-Fajr\nVerses: 30\nAllah speaks about the fate of past nations who were destroyed for their arrogance and disobedience.\n";
                break;
            case 90:
                cout << "Al-Balad\nVerses: 20\nAllah reminds humans of the hardships of life and the importance of charity and good deeds.\n";
                break;
             case 91:
                cout << "Ash-Shams\nVerses: 15\nAllah speaks about the balance in the creation of the universe and the human soul.\n";
                break;
            case 92:
                cout << "Al-Lail\nVerses: 21\nAllah speaks about the contrasts between the righteous and the wicked.\n";
                break;
            case 93:
                cout << "Adh-Dhuha\nVerses: 11\nAllah reminds the Prophet of the blessings He has bestowed upon him.\n";
                break;
            case 94:
                cout << "Ash-Sharh\nVerses: 8\nAllah speaks about the ease that follows hardship and the blessings of patience.\n";
                break;
            case 95:
                cout << "At-Tin\nVerses: 8\nAllah swears by the fig tree and speaks about the creation of man and his potential for greatness.\n";
                break;
            case 96:
                cout << "Al-Alaq\nVerses: 19\nAllah commands the Prophet to read in the name of Allah, the Creator, and reminds humanity of their origins.\n";
                break;
            case 97:
                cout << "Al-Qadr\nVerses: 5\nAllah describes the greatness of the Night of Decree and its significance.\n";
                break;
            case 98:
                cout << "Al-Bayyina\nVerses: 8\nAllah speaks about the clear evidence of the truth and the fate of those who reject it.\n";
                break;
            case 99:
                cout << "Az-Zalzalah\nVerses: 8\nAllah describes the earthquake that will occur on the Day of Judgment and the reckoning of deeds.\n";
                break;
            case 100:
                cout << "Al-Adiyat\nVerses: 11\nAllah speaks about the heedlessness of humans despite the signs of Allah's power in nature.\n";
                break;
            case 101:
                cout << "Al-Qari'ah\nVerses: 11\nAllah describes the catastrophic events of the Day of Judgment and the consequences for the wicked.\n";
                break;
            case 102:
                cout << "At-Takathur\nVerses: 8\nAllah warns against the distractions of worldly possessions and urges reflection on the hereafter.\n";
                break;
            case 103:
                cout << "Al-Asr\nVerses: 3\nAllah speaks about the importance of time and the necessity of good deeds and patience.\n";
                break;
            case 104:
                cout << "Al-Humazah\nVerses: 9\nAllah condemns those who backbite and slander others, warning them of severe punishment.\n";
                break;
            case 105:
                cout << "Al-Fil\nVerses: 5\nAllah recounts the story of the army of the elephant and how He destroyed them to protect the Kaabah.\n";
                break;
            case 106:
                cout << "Quraish\nVerses: 4\nAllah speaks about the blessings He gave to the tribe of Quraish and the importance of gratitude.\n";
                break;
            case 107:
                cout << "Al-Ma'un\nVerses: 7\nAllah condemns those who refuse to help others and warns of punishment for their neglect.\n";
                break;
            case 108:
                cout << "Al-Kawthar\nVerses: 3\nAllah speaks about His abundant blessings and urges gratitude and worship.\n";
                break;
            case 109:
                cout << "Al-Kafirun\nVerses: 6\nAllah rejects the disbelievers' demands for compromise in worship and emphasizes the distinction between belief and disbelief.\n";
                break;
            case 110:
                cout << "An-Nasr\nVerses: 3\nAllah speaks about His help and the victory over the disbelievers, calling for gratitude and repentance.\n";
                break;
            case 111:
                cout << "Al-Masad\nVerses: 5\nAllah condemns Abu Lahab and his wife for their hostility toward the Prophet.\n";
                break;
            case 112:
                cout << "Al-Ikhlas\nVerses: 4\nAllah emphasizes His oneness and the purity of His essence.\n";
                break;
            case 113:
                cout << "Al-Falaq\nVerses: 5\nAllah seeks refuge from the evil of creation, especially from harmful forces like envy and sorcery.\n";
                break;
            case 114:
                cout << "An-Nas\nVerses: 6\nAllah seeks refuge from the evil of harmful creatures and the whisperings of Satan.\n";
                break;
            default:
                cout << "Invalid number. Please enter a number between 1 and 114.\n";
                break;
        }
    }
};

class ManzilInfo {
public:
    void displayManzil(int manzil) {
        switch (manzil) {
            case 1:
                cout << "\nHere's detailed information about the 1st Manzil of the Quran:\n\n";
                cout << "First Manzil:\n";
                cout << "Covers Surah Al-Fatihah to Surah Al-A'raf (Surah 1-7)\n";
                cout << "Consists of 7 Surah's\n";
                cout << "Contains 570 verses\n";
                break;
            case 2:
                cout << "\nHere's detailed information about the 2nd Manzil of the Quran:\n\n";
                cout << "Second Manzil:\n";
                cout << "Covers Surah Al-Anfal to Surah Al-Isra (Surah 8-17)\n";
                cout << "Consists of 10 Surah's\n";
                cout << "Contains 719 verses\n";
                break;
            case 3:
                cout << "\nHere's detailed information about the 3rd Manzil of the Quran:\n\n";
                cout << "Third Manzil:\n";
                cout << "Covers Surah Al-Kahf to Surah Al-Furqan (Surah 18-25)\n";
                cout << "Consists of 8 Surah's\n";
                cout << "Contains 621 verses\n";
                break;
            case 4:
                cout << "\nHere's detailed information about the 4th Manzil of the Quran:\n\n";
                cout << "Fourth Manzil:\n";
                cout << "Covers Surah Ash-Shu'ara to Surah Al-Ahzab (Surah 26-33)\n";
                cout << "Consists of 8 Surah's\n";
                cout << "Contains 593 verses\n";
                break;
            case 5:
                cout << "\nHere's detailed information about the 5th Manzil of the Quran:\n\n";
                cout << "Fifth Manzil:\n";
                cout << "Covers Surah Al-Saba to Surah Al-Fussilat (Surah 34-41)\n";
                cout << "Consists of 8 Surah's\n";
                cout << "Contains 537 verses\n";
                break;
            case 6:
                cout << "\nHere's detailed information about the 6th Manzil of the Quran:\n\n";
                cout << "Sixth Manzil:\n";
                cout << "Covers Surah Ash-Shura to Surah Al-Ahqaf (Surah 42-46)\n";
                cout << "Consists of 5 Surah's\n";
                cout << "Contains 526 verses\n";
                break;
            case 7:
                cout << "\nHere's detailed information about the 7th Manzil of the Quran:\n\n";
                cout << "Seventh Manzil:\n";
                cout << "Covers Surah Muhammad to Surah An-Nas (Surah 47-114)\n";
                cout << "Consists of 68 Surah's\n";
                cout << "Contains 584 verses\n";
                break;
            default:
                cout << "\nInvalid input! Please enter a number between 1 and 7.\n";
                break;
        } 
    }
};

int main() {
    QuranSystem q;
    q.intro();

    ParahInfo pi; // Create an object of ParahInfo
    SurahInfo si; // Create an object of SurahInfo
    ManzilInfo mi; // Create an object of ManzilInfo

    while (true) {
        int b;
        cout << "\nEnter Number From 1 to 4 or enter any other number to exit: ";
        cin >> b;

        switch (b) { // Correctly opened switch block
            case 1: { // Use curly braces for case blocks if you declare variables inside
                int parahNum;
                cout << "Enter Parah number (1-30): ";
                cin >> parahNum;
                pi.displayParah(parahNum);
                break;
            }
            case 2: {
                int surahNum;
                cout << "Enter Surah number (1-114): ";
                cin >> surahNum;
                si.displaySurah(surahNum);
                break;
            }
            case 3: {
                int manzilNum;
                cout << "Enter Manzil number (1-7): ";
                cin >> manzilNum;
                mi.displayManzil(manzilNum);
                break;
            }
            case 4:
                cout << "\nExiting program. Thanks for using.\n";
                return 0; // Exit the program
            default:
                cout << "\nInvalid choice. Please enter a number from 1 to 4 to select an option, or 4 to exit.\n";
                break;
        }
    }
    return 0; // This return is technically unreachable if case 4 is hit, but good practice.
}
