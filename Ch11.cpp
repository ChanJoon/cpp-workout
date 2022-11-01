/* Ch11 Working with Classes
- Operator overloading
- Friend functions
- Overloading the << operator for output
- State members
- Using rand() to generate random values
- Automatic conversions and type casts for classes
- Class conversion functions
*/

#if 0
Operator Overloading

Time::Time()
{
	Time Time::operator+(const Time & t) const
	{
		Time sum;
		sum.minutes = minutes + t.minutes;
		sum.hours = hours + t.hours + sum.minutes / 60;
		sum.minutes %= 60;
		return sum;
	}

	Time Time::operator-(const Time & t) const
	{
		Time diff;
		int tot1, tot2;
		tot1 = t.minutes + 60 * t.hours;
		tot2 = minutes + 60 * hours;
		diff.minutes = (tot2 - tot1) % 60;
		diff.hours = (tot2 - tot1) / 60;
		return diff;
	}

	Time Time::operator*(double mult) const
	{
		Time result;
		long totalminutes = hours * mult * 60 + minutes * mult;
		result.hours = totalminutes / 60;
		result.minutes = totalminutes % 60;
		return result;
	}
}

#endif

#if 0
Introducing Friends

void operator<<(ostream & os, const Time & t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	// This lets you use cout << trip;
}

ostream & operator<< (ostream & os, const Time & t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}

#endif
//584pg