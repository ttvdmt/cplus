#include <vector>
#include <iostream>
#include <string>

class Time {
private:
	int mHours, mMinutes, mSeconds;
public:
	Time(int hours, int minutes, int seconds)
	{
		mHours = hours;
		mMinutes = minutes;
		mSeconds = seconds;
	}

	Time(std::string_view s)
	{
		std::string s1 = s.data();
		int hours = std::stoi(s1.substr(0, 2), nullptr, 10);
		int minutes = std::stoi(s1.substr(3, 2), nullptr, 10);
		int seconds = std::stoi(s1.substr(6, 2), nullptr, 10);
		Time(hours, minutes, seconds);
	}

	Time operator+(Time& b) const
	{
		int flag = 0;
		int seconds1 = seconds() + b.seconds();
		if (seconds1 > 60)
		{
			seconds1 -= 60;
			flag = 1;
		}
		int minutes1 = minutes() + b.minutes() + flag;
		if (minutes1 > 60)
		{
			minutes1 -= 60;
			flag = 1;
		}
		else
		{
			flag = 0;
		}
		int hours1 = hours() + b.hours() + flag;
		return Time(hours1, minutes1, seconds1);
	}

	int hours() const
	{
		return mHours;
	}

	int minutes() const
	{
		return mMinutes;
	}

	int seconds() const
	{
		return mSeconds;
	}

	friend std::ostream& operator<<(std::ostream& out, Time& t)
	{
		std::cout << t.hours() << ' ' << t.minutes() << ' ' << t.seconds() << std::endl;
		return out;
	}
};

std::vector<Time> getTimesFromString(std::string_view s)
{
	std::vector<Time> times;
	std::string s1 = s.data();
	while (!s1.empty())
	{
		Time t(s1.substr(0, 8));
		times.push_back(t);
		s1.erase(0, 9);
	}
	return times;
}

Time sumTimes(const std::vector<Time>& v)
{
	Time t = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		Time v1 = v[i];
		t = t + v1;
	}
	return t;
}

int main()
{
	std::string times = {"11:20:25 11:20:25"};
	auto vtimes = getTimesFromString(times);
	auto sum = sumTimes(vtimes);

	std::cout << sum << std::endl;
}