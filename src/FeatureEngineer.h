//
// Created by dennis gega on 7/7/25.
//

#ifndef FEATURE_ENGINEER_H
#define FEATURE_ENGINEER_H
#include <vector>
#include "Player.h"

template<typename T>
struct MinMax {
    T min = std::numeric_limits<T>::max();
    T max = std::numeric_limits<T>::min();

    void update(T value) {
        min = std::min(min, value);
        max = std::max(max, value);
    }

    double normalize(T value) const {
        if (max == min) return 0;
        return static_cast<double>(value - min) / (max - min);
    }
};

struct PlayerStats {
    MinMax<int> ages;
    MinMax<int> goals;
    MinMax<int> assists;
    MinMax<double> goals_per_90;
    MinMax<double> assists_per_90;
    MinMax<double> contributions_per_90;
    MinMax<long long> values;
};

/**
 * @class FeatureEngineer
 * @brief Provides functionalities for feature engineering, specifically
 *        normalization of numerical attributes for a collection of players.
 */
class FeatureEngineer {
public:
    static void normalizeNumericalFeatures(std::vector<Player>& players);
    static void calculateIndividualPercentiles(std::vector<Player> &players);
    static void calculatePerformanceScore(std::vector<Player> &players);
    static void calculateUndervaluationScore(std::vector<Player> &players);
    static void sortByUndervaluationScore(std::vector<Player> &players);
    void generateReport(const std::vector<Player>& players, int num_top_players);
private:
    void printPositionHeader(Position pos);  // Add this line
    template<typename T>
    static double calculatePercentileRank(std::vector<T> &values, T value);

    static PlayerStats calculateStats(std::vector<Player> &players);
    static void applyNormalization(std::vector<Player> &players, const PlayerStats &stats);

    static std::vector<int> all_ages;
    static std::vector<int> all_goals;
    static std::vector<int> all_assists;
    static std::vector<double> all_goals_per_90;
    static std::vector<double> all_assists_per_90;
    static std::vector<double> all_contributions_per_90;
    static std::vector<long long> all_values;
};

#endif //FEATURE_ENGINEER_H
