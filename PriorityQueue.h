#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <queue>
#include <functional>

// Reservation structure storing user id and book id with priority (e.g. request time)
struct Reservation {
    int userId;
    int bookId;
    int priority; // lower value means higher priority (earlier request)
};

struct ReservationCompare {
    bool operator()(const Reservation &a, const Reservation &b) const {
        return a.priority > b.priority; // min-heap behavior
    }
};

using ReservationQueue = std::priority_queue<Reservation,
                                            std::vector<Reservation>,
                                            ReservationCompare>;

#endif // PRIORITYQUEUE_H
