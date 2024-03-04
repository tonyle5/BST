//
// Created by Tony Le on 03/04/24.
//

#ifndef WEBSITE_H
#define WEBSITE_H

#include "myUtil.h"

class Website {
  private:
    /**
     * The topic of the website.
     */
    char* topic = nullptr;

    /**
     * The keyword of the website.
     */
    char* keyword = nullptr;

    /**
     * URL of the website.
     */
    char* address = nullptr;

    /**
     * Summary of the website.
     */
    char* summary = nullptr;

    /**
     * Review about the website.
     */
    char* review = nullptr;

    /**
     * Rating of the website (1-5 stars – 1 being not very useful, 5 being
     * very useful).
     */
    unsigned short int rating;

  public:
    /**
     * Default constructor.
     */
    Website();

    /**
     * Constructor with parameters.
     *
     * @param topic The topic of the website.
     * @param keyword  The keyword  of the website.
     * @param address The address of the website.
     * @param summary The summary of the website.
     * @param review The review of the website.
     * @param rating The rating of the website (1-5 stars – 1 being not very
     * useful, 5 being very useful).
     */
    Website(const char* topic, const char* keyword, const char* address,
            const char* summary, const char* review,
            unsigned short int rating);

    /**
     * Copy constructor.
     *
     * @param other The website object to be copied.
     */
    Website(const Website& other);

    /**
     * Copy assignment operator.
     *
     * @param other The website object to be assigned.
     * @return Reference to the updated website object.
     */
    Website& operator=(const Website& other);

    /**
     * This function prints the data using a particular output stream.
     *
     * @param os The output stream.
     * @return void
     */
    void printInformation(ostream& os) const;

    /**
     * Destructor.
     */
    ~Website();

    /**
     * Get the topic of the website.
     *
     * @return The topic of the website.
     */
    const char* getTopic() const;

    /**
     * Get the keyword of the website.
     *
     * @return The keyword of the website.
     */
    const char* getKeyword() const;

    /**
     * Get the address of the website.
     *
     * @return The address of the website.
     */
    const char* getAddress() const;

    /**
     * Get the summary of the website.
     *
     * @return The summary of the website.
     */
    const char* getSummary() const;

    /**
     * Get the review of the website.
     *
     * @return The review of the website.
     */
    const char* getReview() const;

    /**
     * Get the rating of the website.
     *
     * @return The rating of the website.
     */
    unsigned short int getRating() const;

    /**
     * Set the topic of the website.
     *
     * @param topic The topic of the website.
     */
    void setTopic(const char* topic);

    /**
     * Set the keyword of the website.
     *
     * @param keyword The keyword of the website.
     */
    void setKeyword(const char* keyword);

    /**
     * Set the address of the website.
     *
     * @param address The address of the website.
     */
    void setAddress(const char* address);

    /**
     * Set the summary of the website.
     *
     * @param summary The summary of the website.
     */
    void setSummary(const char* summary);

    /**
     * Set the review of the website.
     *
     * @param review The review of the website.
     */
    void setReview(const char* review);

    /**
     * Set the rating of the website.
     *
     * @param rating The rating of the website.
     */
    void setRating(unsigned short int rating);

  private:
    /**
     * Initializes the website's properties.
     *
     * @param topic The topic of the website.
     * @param address The address of the website.
     * @param summary The summary of the website.
     * @param review The review of the website.
     * @param rating The rating of the website (1-5 stars – 1 being not very
     * useful, 5 being very useful).
     * @return None
     */
    void init(const char* topic = nullptr, const char* keyword = nullptr,
              const char* address = nullptr, const char* summary = nullptr,
              const char* review = nullptr, unsigned short int rating = 0);
};

#endif  // WEBSITE_H
