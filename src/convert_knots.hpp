double knots_to_miles_per_minute(int knot){
    double mph = (knot)*(6076.0/5280.0);
	double mpm = mph / 60.0;
	return mpm;
}
