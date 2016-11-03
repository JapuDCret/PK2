class Auto
{
public:
	const char* name;
	
	Auto(const char* name, int ps);
	int getPS();
private:
	int ps;
};