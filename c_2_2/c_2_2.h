class Date
{
private:
	static int days[13];
	int m_year,m_month,m_day;
	
	void Date::next();
public:
	Date();
	Date::Date(int _year, int _month, int _day);
	~Date();
	char * GetDate();
	void GetFuture(int _days);
	Date operator+ (int n);
	int operator- (Date n);
	operator int ();
	operator long ();
};
