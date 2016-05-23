class Voyage {
	public:
	char numVoyage[10]; //номер рейса
	char date[10]; //дата вылета
	char way[40]; //направление рейса
	int sit; //количество мест
	int freeSit; //количество свободных мест
	void findVo (class Voyage *ghul, int l);//поиск рейса
	int SaveVo(char *file1, class Voyage *ghul, int l);// сохранение данных рейса в файл
	void ShowVo (class Voyage *ghul, int l);//вывод списка рейсов
	int inputVo (char *file1);//добавление рейса
	void DelVo (char *file1,char *file2, class Voyage *ghul, class Passenger *vad, int l, int k);//удаление рейса
  };

class Passenger: public Voyage{
	public:
	char name[30]; //имя
	char surname[30]; //отчество
	char secname[30]; //фамилия
	int pasport; //номер папорта
	char numTicket[10]; //номер билета
	char numTrip[10]; //номер рейса
	int SavePass(char *file2, class Passenger *vad, int k);//сохранение данных пассажиров в файл
	void ShowPass(class Passenger *vad, int k);//вывод списка пассажиров
	void findPass (class Passenger *vad, int k);//поиск пассажиров
	int inputPass (char *file1, char *file2, class Voyage *ghul, int l);//добавление пассажира
	void DelPass (char *file1, char *file2, class Passenger *vad, class Voyage *ghul,int k, int l);//удаление пассажира
  };

class Voyage *LoadVo(char *file1, class Voyage *ghul, int *hush);//загрузка данных рейсов из базы
class Passenger *LoadPass(char *file2, class Passenger *vad, int *hush);//загрузка данных пассажиров из базы
