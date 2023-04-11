#include "Rent.h"
Rent::Rent(const unsigned int &_id, Client *_client, Vehicle *_vehicle, const boost::posix_time::ptime &_beginTime)
{
    id = _id;
    client = _client;
    vehicle = _vehicle;

    if(_beginTime != boost::posix_time::not_a_date_time) {
        beginTime = _beginTime;
    }
    else
    {
        beginTime = boost::posix_time::second_clock::local_time(); //Jeśli wskazana data rozpoczęcia wypożyczenia jest nieprawidłowa to zostanie użyta data utworzenia obiektu Rent
    }

    endTime = boost::posix_time::not_a_date_time; //"Czas zakończenia wypożyczenia jest ustalany w momencie zakończenia, do tego momentu w polu powinna być wartość not_a_date_time."
    client->getCurrentRents().push_back(this); //Dodajemy nowo utworzony obiekt Rent do listy wypożyczeń odpowiedniego klienta
    vehicle->setRented(true);
}

Rent::~Rent()
{
}

const int Rent::getId() const
{
    return id;
}

const Client *Rent::getClient()
{
    return client;
}

const Vehicle *Rent::getVehicle()
{
    return vehicle;
}

const boost::posix_time::ptime Rent::getBeginTime() const
{
    return beginTime;
}

const boost::posix_time::ptime Rent::getEndTime() const
{
    return endTime;
}

std::string Rent::getRentInfo()
{
    return std::to_string(id) + ": " + client->getClientInfo() + " -> " + vehicle->getVehicleInfo() + " Rozpoczecie: " + boost::posix_time::to_simple_string(beginTime) + " Koniec: " + boost::posix_time::to_simple_string(endTime);
}

void Rent::endRent(boost::posix_time::ptime _endTime)
{
    if(endTime!=boost::posix_time::not_a_date_time) return; //metoda nie może dopuścić do nadpisania już ustalonego czasu zakończenia (nowa wartość może być ustalona tylko wtedy, gdy dotychczasowa wartość to not_a_date_time).
    
    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();;
    if(_endTime != boost::posix_time::not_a_date_time) {
        endTime = _endTime;
    }
    else
    {
        if(beginTime > now) {
            endTime = beginTime;
        }
        else
        {
            endTime = boost::posix_time::second_clock::local_time(); //Jeśli wskazana data zakończenia wypożyczenia jest nieprawidłowa to zostanie użyta data wywołania zakończenia (jeśli nie jest wcześniejsza niż data rozpoczęcia)
        }
    }
}

int Rent::getRentDays()
{
    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
    // jeżeli wypożyczenie nie jest jeszcze zakończone, wartość wynosi 0
    if(endTime==boost::posix_time::not_a_date_time) {
        return 0;
    }
    
    //wypozyczenie zakonczone
    if(now > endTime) {

        // jeżeli wypożyczenie jest zakończone w momencie rozpoczęcia z dokładnością do minuty, jest uznawane za anulowane i wartość także wynosi 0
        if((endTime-beginTime).total_seconds() <= 60) {
            return 0;
        }

        return std::ceil( (double)(endTime - beginTime).hours()/24);

    }
    
    // w pozostałych przypadkach każdy rozpoczęty 24-godzinny okres licząc od momentu rozpoczęcia wypożyczenia 
    // (z zaokrągleniem w dół do pełnej godziny) liczony jest jako kolejna doba wypożyczenia. 
    // A zatem jeśli różnica między czasem rozpoczęcia i zakończenia wynosi od 0 do 23 godzin liczone jest to jako jedna doba; od 24 do 47 godzin - 2 doby, itd.


    return 0;
}
