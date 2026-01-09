@Controller
public class FlightSearchController {

    @Autowired
    private FlightSearchService flightSearchService;

    @GetMapping("/search")
    public String searchFlights(@RequestParam("departure") String departure,
                                @RequestParam("arrival") String arrival,
                                @RequestParam("time") String time, Model model) {
                                    
        List<Flight> flights = flightSearchService.searchFlights(departure, arrival, time);
        model.addAttribute("flights", flights);

        model.findByDepartureAndArrivalAndTime("")
        
        return "searchResults";
    }
}
