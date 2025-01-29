#include <iostream>
#include <vector>
#include <cmath>   
#include <limits>


float euclideanDistance(const std::vector<float>& vec1, const std::vector<float>& vec2) {   // Function to calculate Euclidean distance between two vectors
    float sum = 0.0f;
    for (size_t i = 0; i < vec1.size(); ++i) {
        sum += std::pow(vec1[i] - vec2[i], 2); // Sum 
    }
    return std::sqrt(sum);
}

// Function to find the index of the nearest neighbor
int findNearestNeighbor(const std::vector<std::vector<float>>& embeddings, const std::vector<float>& query) {
    int nearestIndex = -1; 
    float minDistance = std::numeric_limits<float>::max(); 

    for (size_t i = 0; i < embeddings.size(); ++i) {                // Loop through all the embeddings and calculate the Euclidean distance
        float distance = euclideanDistance(embeddings[i], query);
        
        if (distance < minDistance) {
            minDistance = distance;
            nearestIndex = i;
        }
    }

    return nearestIndex;
}

int main() {
    
    std::vector<std::vector<float>> embeddings = {          // Example database
        {1.1f, 2.2f, 3.1f},
        {4.0f, 5.0f, 6.0f},
        {7.1f, 8.2f, 9.1f},
        {1.0f, 2.0f, 3.0f},
        {10.1f, 11.1f, 12.1f}
    };


    std::vector<float> query = {4.1f, 5.1f, 6.1f};       // embedding query 

    int closestIndex = findNearestNeighbor(embeddings, query);      //nearest neighbor

    std::cout << "The index of the closest embedding is: " << closestIndex << std::endl;        // Output the index of the closest match

    return 0;
}
