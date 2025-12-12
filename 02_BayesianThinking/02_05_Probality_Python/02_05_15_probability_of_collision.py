def probability_of_collision(car_1, car_2):
    """
    Calculate the probablity of a collision based on the car turns
    Args:
        car_1 (string): The turning direction of car_1
        car_2 (string): The turning direction of car_2
        
    Returns:
        float: the probability of a collision
    """
    # car_1 and car_2 will each be strings whose value will either be 
    # "L" for left, "S" for straight, or "R" for right.
    probability = 0.0 # you should change this value based on the directions.
    
    if car_1 == "L":
        # Case Car1 L and Car2 L
        if car_2 == "L":
            probability = 0.5
        # Case Car1 L and Car2 S    
        elif car_2 == "S":
            probability = 0.25
        # Case Car1 L and Car2 R (this is all other possible cases)
        else:
            probability = 0.1
        
    elif car_1 == "S":
        # Case Car1 S and Car2 L
        if car_2 == "L":
            probability = 0.25
        # Case Car1 S and Car2 S
        elif car_2 == "S":
            probability = 0.02
        # Case Car1 S and Car2 R (this is all other possible cases)
        else:
            probability = 0.1
        
    else: # Car1 R
        # Case Car1 R and Car2 L
        if car_2 == "L":
            probability = 0.1
        # Case Car1 R and Car2 S
        elif car_2 == "S":
            probability = 0.1
        # Case Car1 R and Car2 R (this is all other possible cases)
        else:
            probability = 0.01
    return probability