public class SpecialDeal
{

    private String departure;
    private String arrival;
    private double cost;
    private Date expirationDate;

    // Getters and setters

    public boolean isExpired() {
        // Check if the special deal has expired
        Date currentDate = new Date();
        return currentDate.after(this.expirationDate);
    }
}
