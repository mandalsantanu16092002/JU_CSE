@Service
public class FlightSearchService {

    @Autowired
    private FlightRepository flightRepository;

    public List<Flight> searchFlights(String departure, String arrival, String time) {
        List<Flight> flights = flightRepository.findByDepartureAndArrivalAndTime(departure, arrival, time);

        // Calculate the total cost and number of legs for each flight
        
        for (Flight flight : flights) {
            flight.calculateTotalCost();
            flight.calculateNumberOfLegs();
        }
        
        
    }
}
