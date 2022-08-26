#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

class Alarm
{
public:
    // constructors and destructor
    Alarm() {}
    ~Alarm() {}
    // other functions
    virtual void Trigger() = 0;
    virtual int change() {}
    string type, time, name;
    int destroy = 0;

protected:
    // member variables are protected to let child classes access them.
};

class RepeatableAlarm : public Alarm
{
public:
    RepeatableAlarm(string type, string time, string name) : type(type), time(time), name(name){};
    ~RepeatableAlarm() {}
    virtual void Trigger()
    {
        cout << "Alarm " << name << " has triggered at " << time << "." << endl;
    }
    int change()
    {
        return (stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2)));
    }

private:
    string type, time, name;
    int destroy = 0;
};

class SnoozeableAlarm : public Alarm
{
public:
    SnoozeableAlarm(string type, string time, string name) : type(type), time(time), name(name){};
    ~SnoozeableAlarm() {}
    virtual void Trigger()
    {
        cout << "Alarm " << name << " has triggered at " << time << ". Snooze? (Y/N)" << endl;
        string judge;
        cin >> judge;
        if (judge == "N")
        {
            destroy = 1;
        }
        else if (judge == "Y")
        {
            string HH, MM;
            stringstream temp_hour, temp_min;
            int hour = stoi(time.substr(0, 2));
            int min = stoi(time.substr(3, 2));
            if (min < 50)
            {
                min += 10;
                temp_hour << hour;
                temp_hour >> HH;
                temp_min << min;
                temp_min >> MM;
            }
            else if (min >= 50)
            {
                min -= 50;
                hour += 1;
                temp_hour << hour;
                temp_hour >> HH;
                temp_min << min;
                temp_min >> MM;
            }
            if (HH.length() < 2)
            {
                HH = "0" + HH;
            }
            if (MM.length() < 2)
            {
                MM = "0" + MM;
            }
            time = HH + ":" + MM;
        }
    }
    int change()
    {
        return (stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2)));
    }

private:
    string type, time, name;
    
};

class AlarmClock
{
public:
    // constructors and destructor
    AlarmClock() {}
    ~AlarmClock() {}
    // other functions
    void AddAlarm(string type, string time, string name);
    void TimeElapse();

private:
    // a container of Alarm*
    vector<Alarm *> alarmData;
    int curr_time = 0;
    // other member variables
};

/**************** Implementations ******************/
void AlarmClock::AddAlarm(string type, string time, string name)
{
    if (type == "R")
    {
        alarmData.push_back(new RepeatableAlarm(type, time, name));
    }
    else if (type == "S")
    {
        alarmData.push_back(new SnoozeableAlarm(type, time, name));
    }
}

void AlarmClock::TimeElapse()
{
    vector<Alarm *>::iterator iter = alarmData.begin();
    while (iter != alarmData.end())
    {
        int set_time = (*(*iter)).change();
        if (set_time == curr_time)
        {
            (*(*iter)).Trigger();
            if ((*(*iter)).destroy == 1)
            {
                iter = alarmData.erase(iter);
            }
            else
            {
                iter++;
            }
        }
        else
        {
            iter++;
        }
    }
    if (curr_time < 1440)
    {
        curr_time += 1;
    }
    else
    {
        curr_time = 0;
    }
}

/**************** Input function ******************/
void Input(AlarmClock &clock)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        string type, time, name;
        cin >> type >> time >> name;
        clock.AddAlarm(type, time, name);
    }
}

int main()
{
    AlarmClock clock;
    for (int days = 0; days < 3; days++)
    {
        cout << "Do you want to add any alarms?" << endl;
        Input(clock);
        for (int minute = 0; minute < 24 * 60; minute++)
        {
            clock.TimeElapse();
        }
        cout << "A day has elapsed." << endl;
    }
}
