public class Flight {
    
    private String departure;
    private String arrival;
    private String time;
    private double baseCost;
    private int numberOfLegs;
    private double totalCost;

    // Getters and setters

    public void calculateTotalCost() {
        // Calculate the total cost based on the base cost and number of legs
        this.totalCost = this.baseCost * this.numberOfLegs;
    }

    public void calculateNumberOfLegs() {
        // Calculate the number of legs based on the departure and arrival cities
        this.numberOfLegs = ... // implementation
    }
}
