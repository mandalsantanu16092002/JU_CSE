@Controller
public class SpecialDealsController {

    @Autowired
    private SpecialDealsService specialDealsService;

    @GetMapping("/")
    public String showSpecialDeals(Model model) {
        List<SpecialDeal> specialDeals = specialDealsService.getSpecialDeals();
        model.addAttribute("specialDeals", specialDeals);
        return "specialDeals";
    }
}
