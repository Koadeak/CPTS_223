begin = std::chrono::steady_clock::now();
    assert((*hash)[97] == 97);
    end = std::chrono::steady_clock::now();
    myfile << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    hash->erase(97);
    end = std::chrono::steady_clock::now();
    myfile << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    assert((*hash)[10000] == 10000);
    end = std::chrono::steady_clock::now();
    myfile << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[ms]" << std::endl;

    myfile << "current size: " << hash->size() << " bucket count: " << hash->get_bucket_count()
           << " load factor: " << hash->load_factor() << std::endl;
    hash->clear();