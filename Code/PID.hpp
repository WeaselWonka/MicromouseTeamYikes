//PID.h


class PID
{
    public:
    PID(double target_speed, int sample_time, double kp, double ki, double kd);
    double compute(double current_rotations);
    void setTarget(int new_target);
    void setTunings(double& Kp, double& Ki, double& Kd);
    void setSampleTime(int NewSampleTime);
	void reset();
    private:
	double target_speed;
    int sampleTime;
    double kp, ki, kd;
    unsigned long lastTime;
    double current_speed, rotation_change_output;
    double integral_term, lastInput;
	int last_num_rotations;

};




