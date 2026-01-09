@Service
public class SpecialDealsService {

    @Autowired
    private SpecialDealRepository specialDealRepository;

    public List<SpecialDeal> getSpecialDeals() {
        List<SpecialDeal> specialDeals = specialDealRepository.findCurrentDeals();
        return specialDeals;
    }
}
