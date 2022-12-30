#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <ctime>

#include <map>
#include <unordered_map>

//types de conversions disponible
enum TIME_TYPE
{
	MILLISECONDES,
	SECONDES,
	MINUTES,
	HOURS,
};

class Timer
{
public:
	//initialisation du timer avec l'id donne
	static void start(int id)
  {
    auto s = std::chrono::steady_clock::now();
  	times.insert({ id, s });
  }
	//recuperation du temps ecoule d'apres l'id donne et de l'echelle de temps demandee
	static float end(int id, TIME_TYPE timeType)
  {
    float dt = 0.0f;
		//on verifie si on connais l'id donne
    if (!times.count(id))
      return dt;
		//on recupere le temps ecoule pour l'id donne
    auto s = times[id];
    times.erase(id);
    auto e = std::chrono::steady_clock::now();
    switch (timeType)
    {
    case TIME_TYPE::MILLISECONDES:
      dt = std::chrono::duration_cast<std::chrono::milliseconds>(e - s).count();
      break;
    case TIME_TYPE::SECONDES:
      dt = std::chrono::duration_cast<std::chrono::seconds>(e - s).count();
      break;
    case TIME_TYPE::MINUTES:
      dt = std::chrono::duration_cast<std::chrono::minutes>(e - s).count();
      break;
    case TIME_TYPE::HOURS:
      dt = std::chrono::duration_cast<std::chrono::hours>(e - s).count();
      break;
    }
    return dt;
  }
private:
	static std::unordered_map<int, std::chrono::steady_clock::time_point> times;
};
std::unordered_map<int, std::chrono::steady_clock::time_point> Timer::times;

#endif
