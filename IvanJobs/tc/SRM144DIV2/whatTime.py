class Time:
    def whatTime(self, seconds):
        h, m, s = seconds / (60 * 60), (seconds/60) % 60, seconds % 60

        return ':'.join([str(h), str(m), str(s)])
