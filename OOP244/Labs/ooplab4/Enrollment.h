class Enrollment {

private:

	char* course;
	char* code;
	int year;
	int term;
	int slot;
	bool check;

public:

	Enrollment(const char* _course, const char* _code, int _year, int _term, int _slot);
	Enrollment();
	~Enrollment();
	void enroll(char* n, char* c, int y, int t, int s);
	bool isEnrolled() const;
	void withdraw();
	bool hasConflict(const Enrollment &other) const;
	void display() const;
};