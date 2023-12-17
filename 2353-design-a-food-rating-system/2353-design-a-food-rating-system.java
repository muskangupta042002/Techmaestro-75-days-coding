import java.util.*;
class Food implements Comparable<Food>{
    public int foodRating;
    public String foodName;
    public Food(int foodRating, String foodName){
        this.foodRating=foodRating;
        this.foodName=foodName;
    }

    @Override
    public int compareTo(Food other){
        if(foodRating == other.foodRating){
            return foodName.compareTo(other.foodName);
        }
        return -1*Integer.compare(foodRating,other.foodRating);

    }
}

class FoodRatings {

    Map<String, Integer> foodRatingMap;
    Map<String,String> foodCuisineMap;
    Map<String,PriorityQueue<Food>> cuisineFoodMap;

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        foodRatingMap = new HashMap<>();
        foodCuisineMap=new HashMap<>();
        cuisineFoodMap=new HashMap<>();

        for (int i = 0; i < foods.length; i++) {
            foodRatingMap.put(foods[i],ratings[i]);
            foodCuisineMap.put(foods[i],cuisines[i]);
            cuisineFoodMap.computeIfAbsent(cuisines[i], k -> new PriorityQueue<>())
                    .add(new Food(ratings[i],foods[i]));
        }

    }

    public void changeRating(String food, int newRating) {
       
        //foodRatingMap[food]=newRating;
       foodRatingMap.put(food, newRating);
        String cuisineName=foodCuisineMap.get(food);
        cuisineFoodMap.get(cuisineName).add(new Food(newRating,food));
        
    }

    public String highestRated(String cuisine) {
        Food highestRated=cuisineFoodMap.get(cuisine).peek();
        while(foodRatingMap.get(highestRated.foodName) != highestRated.foodRating){
            cuisineFoodMap.get(cuisine).poll();
            highestRated=cuisineFoodMap.get(cuisine).peek();
        }
        return highestRated.foodName;
    }

    // private void updateRating(String cuisine, String dish, int newRating) {
    //     List<DishRating> dishRatings = cuisineMap.get(cuisine);
    //     if (dishRatings != null) {
    //         for (DishRating dishRating : dishRatings) {
    //             if (dishRating.getDish().equals(dish)) {
    //                 dishRating.setRating(newRating);
    //                 break; // Break the loop once the dish is found and updated
    //             }
    //         }
    //     }
    // }
}
